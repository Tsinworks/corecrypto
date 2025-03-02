/*
 * Copyright (c) 2012,2015,2016,2018 Apple Inc. All rights reserved.
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

/* Autogenerated file - Use scheme ccdh_gen_gp to regenerate */
#include <corecrypto/ccdh_priv.h>
#include <corecrypto/ccsrp_gp.h>

static ccdh_gp_decl_static(1024) _ccsrp_gp_rfc5054_1024 =
{
    .hp = {
        .n = ccn_nof(1024),
        .options = 0,
        .mod_prime = cczp_mod
    },
    .p = {
        /* prime */
        CCN64_C(9f,c6,1d,2f,c0,eb,06,e3),CCN64_C(fd,51,38,fe,83,76,43,5b),
        CCN64_C(2f,d4,cb,f4,97,6e,aa,9a),CCN64_C(68,ed,bc,3c,05,72,6c,c0),
        CCN64_C(c5,29,f5,66,66,0e,57,ec),CCN64_C(82,55,9b,29,7b,cf,18,85),
        CCN64_C(ce,8e,f4,ad,69,b1,5d,49),CCN64_C(5d,c7,d7,b4,61,54,d6,b6),
        CCN64_C(8e,49,5c,1d,60,89,da,d1),CCN64_C(e0,d5,d8,e2,50,b9,8b,e4),
        CCN64_C(38,3b,48,13,d6,92,c6,e0),CCN64_C(d6,74,df,74,96,ea,81,d3),
        CCN64_C(9e,a2,31,4c,9c,25,65,76),CCN64_C(60,72,61,87,75,ff,3c,0b),
        CCN64_C(9c,33,f8,0a,fa,8f,c5,e8),CCN64_C(ee,af,0a,b9,ad,b3,8d,d6)
    },
    .recip = {
        /* recip */
        CCN64_C(fb,9a,6d,ce,50,c7,02,b2),CCN64_C(62,82,f7,1f,43,4b,2d,33),
        CCN64_C(19,06,35,15,e2,55,53,64),CCN64_C(91,c3,be,7b,f0,b0,a1,ec),
        CCN64_C(fe,e7,e9,24,72,57,7c,14),CCN64_C(8e,99,ff,fb,1c,ed,29,e1),
        CCN64_C(ab,2a,0e,6e,52,63,81,e1),CCN64_C(31,b2,61,36,ff,62,2e,ed),
        CCN64_C(22,ef,4c,82,07,d4,99,f7),CCN64_C(ca,99,c7,b1,b9,56,b8,19),
        CCN64_C(dd,a3,bf,2a,7f,ff,38,31),CCN64_C(23,52,f4,8b,e2,b9,87,26),
        CCN64_C(7f,c5,06,dc,cb,06,85,8e),CCN64_C(45,28,08,a3,53,ec,97,28),
        CCN64_C(e8,64,2c,dd,3a,c1,f2,d3),CCN64_C(12,92,90,76,b7,ea,13,1e),
        CCN8_C(01)
    },
    .g = {
        /* g */
        CCN64_C(00,00,00,00,00,00,00,02),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN8_C(00)
    },
    .q = {
        /* q */
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN64_C(00,00,00,00,00,00,00,00),
        CCN64_C(00,00,00,00,00,00,00,00),CCN8_C(00)
    },
    .l = 160,
};

ccdh_const_gp_t ccsrp_gp_rfc5054_1024(void)
{
    return (ccdh_const_gp_t)(cczp_const_t)(const cc_unit *)&_ccsrp_gp_rfc5054_1024;
}

