/*
 * Copyright (c) 2016,2018 Apple Inc. All rights reserved.
 *
 * corecrypto Internal Use License Agreement
 *
 * IMPORTANT:  This Apple corecrypto software is supplied to you by Apple Inc. ("Apple")
 * in consideration of your agreement to the following terms, and your download or use
 * of this Apple software constitutes acceptance of these terms.  If you do not agree
 * with these terms, please do not download or use this Apple software.
 *
 * 1.    As used in this Agreement, the term "Apple Software" collectively means and
 * includes all of the Apple corecrypto materials provided by Apple here, including
 * but not limited to the Apple corecrypto software, frameworks, libraries, documentation
 * and other Apple-created materials. In consideration of your agreement to abide by the
 * following terms, conditioned upon your compliance with these terms and subject to
 * these terms, Apple grants you, for a period of ninety (90) days from the date you
 * download the Apple Software, a limited, non-exclusive, non-sublicensable license
 * under Apple’s copyrights in the Apple Software to make a reasonable number of copies
 * of, compile, and run the Apple Software internally within your organization only on
 * devices and computers you own or control, for the sole purpose of verifying the
 * security characteristics and correct functioning of the Apple Software; provided
 * that you must retain this notice and the following text and disclaimers in all
 * copies of the Apple Software that you make. You may not, directly or indirectly,
 * redistribute the Apple Software or any portions thereof. The Apple Software is only
 * licensed and intended for use as expressly stated above and may not be used for other
 * purposes or in other contexts without Apple's prior written permission.  Except as
 * expressly stated in this notice, no other rights or licenses, express or implied, are
 * granted by Apple herein.
 *
 * 2.    The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES
 * OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING
 * THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS,
 * SYSTEMS, OR SERVICES. APPLE DOES NOT WARRANT THAT THE APPLE SOFTWARE WILL MEET YOUR
 * REQUIREMENTS, THAT THE OPERATION OF THE APPLE SOFTWARE WILL BE UNINTERRUPTED OR
 * ERROR-FREE, THAT DEFECTS IN THE APPLE SOFTWARE WILL BE CORRECTED, OR THAT THE APPLE
 * SOFTWARE WILL BE COMPATIBLE WITH FUTURE APPLE PRODUCTS, SOFTWARE OR SERVICES. NO ORAL
 * OR WRITTEN INFORMATION OR ADVICE GIVEN BY APPLE OR AN APPLE AUTHORIZED REPRESENTATIVE
 * WILL CREATE A WARRANTY.
 *
 * 3.    IN NO EVENT SHALL APPLE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ARISING
 * IN ANY WAY OUT OF THE USE, REPRODUCTION, COMPILATION OR OPERATION OF THE APPLE
 * SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING
 * NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * 4.    This Agreement is effective until terminated. Your rights under this Agreement will
 * terminate automatically without notice from Apple if you fail to comply with any term(s)
 * of this Agreement.  Upon termination, you agree to cease all use of the Apple Software
 * and destroy all copies, full or partial, of the Apple Software. This Agreement will be
 * governed and construed in accordance with the laws of the State of California, without
 * regard to its choice of law rules.
 *
 * You may report security issues about Apple products to product-security@apple.com,
 * as described here:  https://www.apple.com/support/security/.  Non-security bugs and
 * enhancement requests can be made via https://bugreport.apple.com as described
 * here: https://developer.apple.com/bug-reporting/
 *
 * EA1350
 * 10/5/15
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <zlib.h>
#include <corecrypto/ccaes.h>
#include "ClockServices.h"

// extern void ccdigest_update(const struct ccdigest_info *di, ccdigest_ctx_t ctx, size_t len, const void *data);

typedef struct
{
    const struct ccmode_ecb *ecb;
	const void *key;
	size_t nblocks;
	const void *dataIn;
	void *dataOut;
} Parameters;


// this templtae works for both encrypt and decrypt
static void BlockECB(const Parameters *parameters)
{
	parameters->ecb->ecb(parameters->key, parameters->nblocks, parameters->dataIn, parameters->dataOut);
}


static void Driver(unsigned int iterations, void *parameters)
{
    Parameters *p = (Parameters *) parameters;
    while (iterations--) {
        BlockECB(p);
	}
}

extern uint32_t	single_test;

void thermalAES_ECB(uint32_t    ITERATIONS, uint32_t    data_size);

void thermalAES_ECB(uint32_t    ITERATIONS, uint32_t    data_size)
{


	char	*dataIn, *dataEncrypted, *dataDecrypted;
	uint32_t		i;
	double TotalETime = 0;
	double TotalDTime = 0;
    uint32_t    NUM_BLOCKS = data_size/16;
    if ((NUM_BLOCKS*16)!=data_size) {
        data_size = 16*NUM_BLOCKS;
        fprintf(stderr,"warning : adjusted data_size to %d\n", data_size);
    }

	const struct ccmode_ecb *encrypt = ccaes_ecb_encrypt_mode();
    const struct ccmode_ecb *decrypt = ccaes_ecb_decrypt_mode();
	unsigned int		keyLen=16;
	uint8_t 	gkey[32];

if (!single_test)
	for (i=0;i<32;i++) gkey[i] = arc4random();

	ccecb_ctx_decl(encrypt->size, ekey);
	encrypt->init(encrypt, ekey, keyLen, (const uint8_t *) gkey);

	ccecb_ctx_decl(decrypt->size, dkey);
	decrypt->init(decrypt, dkey, keyLen, (const uint8_t *) gkey);

	if (!(dataIn = calloc(data_size,1))) {
		fprintf(stderr,"error : calloc dataIn %d \n", data_size);
		exit(1);
	}
	if (!(dataEncrypted = calloc(data_size,1))) {
		fprintf(stderr,"error : calloc dataEncrypted %d \n", data_size);
		exit(1);
	}
	if (!(dataDecrypted = calloc(data_size,1))) {
		fprintf(stderr,"error : calloc dataDecrypted %d \n", data_size);
		exit(1);
	}

if (!single_test) {
	for (i=0;i<data_size;i++) { 
			dataIn[i] = arc4random();
			dataEncrypted[i] = dataDecrypted[i] = 0;
	}

	// Encrypted
    {
            Parameters parameters =
            {
                .ecb = encrypt,
				.key = ekey,
				.nblocks = data_size/16,
				.dataIn = dataIn,
				.dataOut = dataEncrypted,
            };
            TotalETime += MeasureNetTimeInCPUCycles(Driver, ITERATIONS, &parameters, 1);

    }
}

	// Decrypted
    {
            Parameters parameters =
            {
                .ecb = decrypt,
				.key = dkey,
				.nblocks = data_size/16,
				.dataIn = dataEncrypted,
				.dataOut = dataDecrypted,
            };
            TotalDTime += MeasureNetTimeInCPUCycles(Driver, ITERATIONS, &parameters, 1);

    }

if (!single_test) {
	for (i=0;i<data_size;i++) if (dataIn[i]!=dataDecrypted[i]) {
			fprintf(stderr, "error at i = %d, %6d %6d %6d\n", i, dataIn[i], dataEncrypted[i], dataDecrypted[i]);
			break;
	}
}

	printf("  aes-ecb : %.2f/%.2f\n", (TotalETime/data_size), (TotalDTime/data_size));

	free(dataIn);
	free(dataEncrypted);
	free(dataDecrypted);

}

/*
    function that tests corner cases (various number of input blocks) with known constants in the key and data
*/
#define Dsize   4096
#define nBlocks (Dsize/16)

uint32_t validate_ecb_checksum[] = { 0xecdfb631, 0xd39bf0fa, 0xc5bb6dbc };

void validateAES_ECB(void);

void validateAES_ECB(void)
{


	unsigned char	dataIn[Dsize], dataEncrypted[Dsize], dataDecrypted[Dsize];
	int		i, j;

	const struct ccmode_ecb *encrypt = ccaes_ecb_encrypt_mode();
    const struct ccmode_ecb *decrypt = ccaes_ecb_decrypt_mode();
    ccecb_ctx_decl(encrypt->size, ekey);
	ccecb_ctx_decl(decrypt->size, dkey);

	unsigned int		keyLen;
	uint8_t 	        gkey[32];
    for (i=0;i<32;i++) gkey[i] = i;
	for (i=0;i<Dsize;i++) dataIn[i] = i; 
    bzero(dataEncrypted,Dsize);
    bzero(dataDecrypted,Dsize);

    for (keyLen=16;keyLen<=32;keyLen+=8) {  /* aes-128/aes-192/aes-224 */

        encrypt->init(encrypt, ekey, keyLen, (const uint8_t *) gkey);
	    decrypt->init(decrypt, dkey, keyLen, (const uint8_t *) gkey);
  
        /* encrypt in nblocks of 1,2,...,10,(256-55) */ 
        j=0; 
        for (i=1;i<=10;i++) { 
            encrypt->ecb(ekey, i, &dataIn[j], &dataEncrypted[j]);
            j+=(i<<4);
        }
        i = (4096-j)>>4;
        encrypt->ecb(ekey, i, &dataIn[j], &dataEncrypted[j]);

        /* decrypt in nblocks of 1,2,...,10,(256-55) */ 
        j=0; 
        for (i=1;i<=10;i++) { 
            decrypt->ecb(dkey, i, &dataEncrypted[j], &dataDecrypted[j]);
            j+=(i<<4);
        }
        i = (4096-j)>>4;
        decrypt->ecb(dkey, i, &dataEncrypted[j], &dataDecrypted[j]);

        /* check whether dataIn == dataDecrypted */
        for (i=0;i<Dsize;i++) {
            if (dataIn[i] != dataDecrypted[i]) {
                fprintf(stderr, "error : ECB mode AES-%d error (mismatched at byte %d\n", keyLen*8, i);
                exit(1);
            }
        }

        /* check crc32 of encrypted data */
        uint32_t    checksum = (uint32_t) (crc32(0, dataEncrypted, Dsize) ^ adler32(0, dataEncrypted, Dsize));
        if (checksum!=validate_ecb_checksum[keyLen/8-2]) {
                fprintf(stderr, "error : encrypted data checksum (crc32^adler32) failed\n");
                exit(2);
        }
    }
    fprintf(stderr, "AES-ECB validated\n");
}
