/*
 * Copyright (c) 2011,2015,2016,2018 Apple Inc. All rights reserved.
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

#ifndef _CORECRYPTO_RFC5114DHGROUPS_H_
#define _CORECRYPTO_RFC5114DHGROUPS_H_

// DH Groups specified in RFC 5114

//2.1.  1024-bit MODP Group with 160-bit Prime Order Subgroup
//
//   The hexadecimal value of the prime is:
//
static struct {
    uint8_t l[1];
    uint8_t p[128];
    uint8_t g[128];
    uint8_t q[20];
} rfc5114_MODP_1024_160= { 
    .l = { 0x00, },
    .p = {
        0xB1,0x0B,0x8F,0x96, 0xA0,0x80,0xE0,0x1D, 0xDE,0x92,0xDE,0x5E, 0xAE,0x5D,0x54,0xEC, 0x52,0xC9,0x9F,0xBC, 0xFB,0x06,0xA3,0xC6,
        0x9A,0x6A,0x9D,0xCA, 0x52,0xD2,0x3B,0x61, 0x60,0x73,0xE2,0x86, 0x75,0xA2,0x3D,0x18, 0x98,0x38,0xEF,0x1E, 0x2E,0xE6,0x52,0xC0,
        0x13,0xEC,0xB4,0xAE, 0xA9,0x06,0x11,0x23, 0x24,0x97,0x5C,0x3C, 0xD4,0x9B,0x83,0xBF, 0xAC,0xCB,0xDD,0x7D, 0x90,0xC4,0xBD,0x70,
        0x98,0x48,0x8E,0x9C, 0x21,0x9A,0x73,0x72, 0x4E,0xFF,0xD6,0xFA, 0xE5,0x64,0x47,0x38, 0xFA,0xA3,0x1A,0x4F, 0xF5,0x5B,0xCC,0xC0,
        0xA1,0x51,0xAF,0x5F, 0x0D,0xC8,0xB4,0xBD, 0x45,0xBF,0x37,0xDF, 0x36,0x5C,0x1A,0x65, 0xE6,0x8C,0xFD,0xA7, 0x6D,0x4D,0xA7,0x08,
        0xDF,0x1F,0xB2,0xBC, 0x2E,0x4A,0x43,0x71,
    },
//
//   The hexadecimal value of the generator is:
//
    .g = {
        0xA4,0xD1,0xCB,0xD5, 0xC3,0xFD,0x34,0x12, 0x67,0x65,0xA4,0x42, 0xEF,0xB9,0x99,0x05, 0xF8,0x10,0x4D,0xD2, 0x58,0xAC,0x50,0x7F,
        0xD6,0x40,0x6C,0xFF, 0x14,0x26,0x6D,0x31, 0x26,0x6F,0xEA,0x1E, 0x5C,0x41,0x56,0x4B, 0x77,0x7E,0x69,0x0F, 0x55,0x04,0xF2,0x13,
        0x16,0x02,0x17,0xB4, 0xB0,0x1B,0x88,0x6A, 0x5E,0x91,0x54,0x7F, 0x9E,0x27,0x49,0xF4, 0xD7,0xFB,0xD7,0xD3, 0xB9,0xA9,0x2E,0xE1,
        0x90,0x9D,0x0D,0x22, 0x63,0xF8,0x0A,0x76, 0xA6,0xA2,0x4C,0x08, 0x7A,0x09,0x1F,0x53, 0x1D,0xBF,0x0A,0x01, 0x69,0xB6,0xA2,0x8A,
        0xD6,0x62,0xA4,0xD1, 0x8E,0x73,0xAF,0xA3, 0x2D,0x77,0x9D,0x59, 0x18,0xD0,0x8B,0xC8, 0x85,0x8F,0x4D,0xCE, 0xF9,0x7C,0x2A,0x24,
        0x85,0x5E,0x6E,0xEB, 0x22,0xB3,0xB2,0xE5,
    },
//
//   The generator generates a prime-order subgroup of size:
//
    .q = {
        0xF5,0x18,0xAA,0x87, 0x81,0xA8,0xDF,0x27, 0x8A,0xBA,0x4E,0x7D, 0x64,0xB7,0xCB,0x9D, 0x49,0x46,0x23,0x53,
    },
};


//2.2.  2048-bit MODP Group with 224-bit Prime Order Subgroup
//
//   The hexadecimal value of the prime is:
//
struct {
    uint8_t l[1];
    uint8_t p[256];
    uint8_t g[256];
    uint8_t q[28];
} rfc5114_MODP_2048_224= { 
    .l = { 0x00, },
    .p =  {
        0xAD,0x10,0x7E,0x1E, 0x91,0x23,0xA9,0xD0, 0xD6,0x60,0xFA,0xA7, 0x95,0x59,0xC5,0x1F, 0xA2,0x0D,0x64,0xE5, 0x68,0x3B,0x9F,0xD1,
        0xB5,0x4B,0x15,0x97, 0xB6,0x1D,0x0A,0x75, 0xE6,0xFA,0x14,0x1D, 0xF9,0x5A,0x56,0xDB, 0xAF,0x9A,0x3C,0x40, 0x7B,0xA1,0xDF,0x15,
        0xEB,0x3D,0x68,0x8A, 0x30,0x9C,0x18,0x0E, 0x1D,0xE6,0xB8,0x5A, 0x12,0x74,0xA0,0xA6, 0x6D,0x3F,0x81,0x52, 0xAD,0x6A,0xC2,0x12,
        0x90,0x37,0xC9,0xED, 0xEF,0xDA,0x4D,0xF8, 0xD9,0x1E,0x8F,0xEF, 0x55,0xB7,0x39,0x4B, 0x7A,0xD5,0xB7,0xD0, 0xB6,0xC1,0x22,0x07,
        0xC9,0xF9,0x8D,0x11, 0xED,0x34,0xDB,0xF6, 0xC6,0xBA,0x0B,0x2C, 0x8B,0xBC,0x27,0xBE, 0x6A,0x00,0xE0,0xA0, 0xB9,0xC4,0x97,0x08,
        0xB3,0xBF,0x8A,0x31, 0x70,0x91,0x88,0x36, 0x81,0x28,0x61,0x30, 0xBC,0x89,0x85,0xDB, 0x16,0x02,0xE7,0x14, 0x41,0x5D,0x93,0x30,
        0x27,0x82,0x73,0xC7, 0xDE,0x31,0xEF,0xDC, 0x73,0x10,0xF7,0x12, 0x1F,0xD5,0xA0,0x74, 0x15,0x98,0x7D,0x9A, 0xDC,0x0A,0x48,0x6D,
        0xCD,0xF9,0x3A,0xCC, 0x44,0x32,0x83,0x87, 0x31,0x5D,0x75,0xE1, 0x98,0xC6,0x41,0xA4, 0x80,0xCD,0x86,0xA1, 0xB9,0xE5,0x87,0xE8,
        0xBE,0x60,0xE6,0x9C, 0xC9,0x28,0xB2,0xB9, 0xC5,0x21,0x72,0xE4, 0x13,0x04,0x2E,0x9B, 0x23,0xF1,0x0B,0x0E, 0x16,0xE7,0x97,0x63,
        0xC9,0xB5,0x3D,0xCF, 0x4B,0xA8,0x0A,0x29, 0xE3,0xFB,0x73,0xC1, 0x6B,0x8E,0x75,0xB9, 0x7E,0xF3,0x63,0xE2, 0xFF,0xA3,0x1F,0x71,
        0xCF,0x9D,0xE5,0x38, 0x4E,0x71,0xB8,0x1C, 0x0A,0xC4,0xDF,0xFE, 0x0C,0x10,0xE6,0x4F,
    },
//
//   The hexadecimal value of the generator is:
//
    .g =  {
        0xAC,0x40,0x32,0xEF, 0x4F,0x2D,0x9A,0xE3, 0x9D,0xF3,0x0B,0x5C, 0x8F,0xFD,0xAC,0x50, 0x6C,0xDE,0xBE,0x7B, 0x89,0x99,0x8C,0xAF,
        0x74,0x86,0x6A,0x08, 0xCF,0xE4,0xFF,0xE3, 0xA6,0x82,0x4A,0x4E, 0x10,0xB9,0xA6,0xF0, 0xDD,0x92,0x1F,0x01, 0xA7,0x0C,0x4A,0xFA,
        0xAB,0x73,0x9D,0x77, 0x00,0xC2,0x9F,0x52, 0xC5,0x7D,0xB1,0x7C, 0x62,0x0A,0x86,0x52, 0xBE,0x5E,0x90,0x01, 0xA8,0xD6,0x6A,0xD7,
        0xC1,0x76,0x69,0x10, 0x19,0x99,0x02,0x4A, 0xF4,0xD0,0x27,0x27, 0x5A,0xC1,0x34,0x8B, 0xB8,0xA7,0x62,0xD0, 0x52,0x1B,0xC9,0x8A,
        0xE2,0x47,0x15,0x04, 0x22,0xEA,0x1E,0xD4, 0x09,0x93,0x9D,0x54, 0xDA,0x74,0x60,0xCD, 0xB5,0xF6,0xC6,0xB2, 0x50,0x71,0x7C,0xBE,
        0xF1,0x80,0xEB,0x34, 0x11,0x8E,0x98,0xD1, 0x19,0x52,0x9A,0x45, 0xD6,0xF8,0x34,0x56, 0x6E,0x30,0x25,0xE3, 0x16,0xA3,0x30,0xEF,
        0xBB,0x77,0xA8,0x6F, 0x0C,0x1A,0xB1,0x5B, 0x05,0x1A,0xE3,0xD4, 0x28,0xC8,0xF8,0xAC, 0xB7,0x0A,0x81,0x37, 0x15,0x0B,0x8E,0xEB,
        0x10,0xE1,0x83,0xED, 0xD1,0x99,0x63,0xDD, 0xD9,0xE2,0x63,0xE4, 0x77,0x05,0x89,0xEF, 0x6A,0xA2,0x1E,0x7F, 0x5F,0x2F,0xF3,0x81,
        0xB5,0x39,0xCC,0xE3, 0x40,0x9D,0x13,0xCD, 0x56,0x6A,0xFB,0xB4, 0x8D,0x6C,0x01,0x91, 0x81,0xE1,0xBC,0xFE, 0x94,0xB3,0x02,0x69,
        0xED,0xFE,0x72,0xFE, 0x9B,0x6A,0xA4,0xBD, 0x7B,0x5A,0x0F,0x1C, 0x71,0xCF,0xFF,0x4C, 0x19,0xC4,0x18,0xE1, 0xF6,0xEC,0x01,0x79,
        0x81,0xBC,0x08,0x7F, 0x2A,0x70,0x65,0xB3, 0x84,0xB8,0x90,0xD3, 0x19,0x1F,0x2B,0xFA,
    },
//
//   The generator generates a prime-order subgroup of size:
//
    .q =  {
        0x80,0x1C,0x0D,0x34, 0xC5,0x8D,0x93,0xFE, 0x99,0x71,0x77,0x10, 0x1F,0x80,0x53,0x5A, 0x47,0x38,0xCE,0xBC, 0xBF,0x38,0x9A,0x99,
        0xB3,0x63,0x71,0xEB,
    }
};

//2.3.  2048-bit MODP Group with 256-bit Prime Order Subgroup
//
//   The hexadecimal value of the prime is:
//
struct {
    uint8_t l[2];
    uint8_t p[256];
    uint8_t g[256];
    uint8_t q[32];
} rfc5114_MODP_2048_256= { 
    .l = { 0x00, },
    .p = {
        0x87,0xA8,0xE6,0x1D, 0xB4,0xB6,0x66,0x3C, 0xFF,0xBB,0xD1,0x9C, 0x65,0x19,0x59,0x99, 0x8C,0xEE,0xF6,0x08, 0x66,0x0D,0xD0,0xF2,
        0x5D,0x2C,0xEE,0xD4, 0x43,0x5E,0x3B,0x00, 0xE0,0x0D,0xF8,0xF1, 0xD6,0x19,0x57,0xD4, 0xFA,0xF7,0xDF,0x45, 0x61,0xB2,0xAA,0x30,
        0x16,0xC3,0xD9,0x11, 0x34,0x09,0x6F,0xAA, 0x3B,0xF4,0x29,0x6D, 0x83,0x0E,0x9A,0x7C, 0x20,0x9E,0x0C,0x64, 0x97,0x51,0x7A,0xBD,
        0x5A,0x8A,0x9D,0x30, 0x6B,0xCF,0x67,0xED, 0x91,0xF9,0xE6,0x72, 0x5B,0x47,0x58,0xC0, 0x22,0xE0,0xB1,0xEF, 0x42,0x75,0xBF,0x7B,
        0x6C,0x5B,0xFC,0x11, 0xD4,0x5F,0x90,0x88, 0xB9,0x41,0xF5,0x4E, 0xB1,0xE5,0x9B,0xB8, 0xBC,0x39,0xA0,0xBF, 0x12,0x30,0x7F,0x5C,
        0x4F,0xDB,0x70,0xC5, 0x81,0xB2,0x3F,0x76, 0xB6,0x3A,0xCA,0xE1, 0xCA,0xA6,0xB7,0x90, 0x2D,0x52,0x52,0x67, 0x35,0x48,0x8A,0x0E,
        0xF1,0x3C,0x6D,0x9A, 0x51,0xBF,0xA4,0xAB, 0x3A,0xD8,0x34,0x77, 0x96,0x52,0x4D,0x8E, 0xF6,0xA1,0x67,0xB5, 0xA4,0x18,0x25,0xD9,
        0x67,0xE1,0x44,0xE5, 0x14,0x05,0x64,0x25, 0x1C,0xCA,0xCB,0x83, 0xE6,0xB4,0x86,0xF6, 0xB3,0xCA,0x3F,0x79, 0x71,0x50,0x60,0x26,
        0xC0,0xB8,0x57,0xF6, 0x89,0x96,0x28,0x56, 0xDE,0xD4,0x01,0x0A, 0xBD,0x0B,0xE6,0x21, 0xC3,0xA3,0x96,0x0A, 0x54,0xE7,0x10,0xC3,
        0x75,0xF2,0x63,0x75, 0xD7,0x01,0x41,0x03, 0xA4,0xB5,0x43,0x30, 0xC1,0x98,0xAF,0x12, 0x61,0x16,0xD2,0x27, 0x6E,0x11,0x71,0x5F,
        0x69,0x38,0x77,0xFA, 0xD7,0xEF,0x09,0xCA, 0xDB,0x09,0x4A,0xE9, 0x1E,0x1A,0x15,0x97,
    },
//
//
//   The hexadecimal value of the generator is:
//
    .g = { 
        0x3F,0xB3,0x2C,0x9B, 0x73,0x13,0x4D,0x0B, 0x2E,0x77,0x50,0x66, 0x60,0xED,0xBD,0x48, 0x4C,0xA7,0xB1,0x8F, 0x21,0xEF,0x20,0x54,
        0x07,0xF4,0x79,0x3A, 0x1A,0x0B,0xA1,0x25, 0x10,0xDB,0xC1,0x50, 0x77,0xBE,0x46,0x3F, 0xFF,0x4F,0xED,0x4A, 0xAC,0x0B,0xB5,0x55,
        0xBE,0x3A,0x6C,0x1B, 0x0C,0x6B,0x47,0xB1, 0xBC,0x37,0x73,0xBF, 0x7E,0x8C,0x6F,0x62, 0x90,0x12,0x28,0xF8, 0xC2,0x8C,0xBB,0x18,
        0xA5,0x5A,0xE3,0x13, 0x41,0x00,0x0A,0x65, 0x01,0x96,0xF9,0x31, 0xC7,0x7A,0x57,0xF2, 0xDD,0xF4,0x63,0xE5, 0xE9,0xEC,0x14,0x4B,
        0x77,0x7D,0xE6,0x2A, 0xAA,0xB8,0xA8,0x62, 0x8A,0xC3,0x76,0xD2, 0x82,0xD6,0xED,0x38, 0x64,0xE6,0x79,0x82, 0x42,0x8E,0xBC,0x83,
        0x1D,0x14,0x34,0x8F, 0x6F,0x2F,0x91,0x93, 0xB5,0x04,0x5A,0xF2, 0x76,0x71,0x64,0xE1, 0xDF,0xC9,0x67,0xC1, 0xFB,0x3F,0x2E,0x55,
        0xA4,0xBD,0x1B,0xFF, 0xE8,0x3B,0x9C,0x80, 0xD0,0x52,0xB9,0x85, 0xD1,0x82,0xEA,0x0A, 0xDB,0x2A,0x3B,0x73, 0x13,0xD3,0xFE,0x14,
        0xC8,0x48,0x4B,0x1E, 0x05,0x25,0x88,0xB9, 0xB7,0xD2,0xBB,0xD2, 0xDF,0x01,0x61,0x99, 0xEC,0xD0,0x6E,0x15, 0x57,0xCD,0x09,0x15,
        0xB3,0x35,0x3B,0xBB, 0x64,0xE0,0xEC,0x37, 0x7F,0xD0,0x28,0x37, 0x0D,0xF9,0x2B,0x52, 0xC7,0x89,0x14,0x28, 0xCD,0xC6,0x7E,0xB6,
        0x18,0x4B,0x52,0x3D, 0x1D,0xB2,0x46,0xC3, 0x2F,0x63,0x07,0x84, 0x90,0xF0,0x0E,0xF8, 0xD6,0x47,0xD1,0x48, 0xD4,0x79,0x54,0x51,
        0x5E,0x23,0x27,0xCF, 0xEF,0x98,0xC5,0x82, 0x66,0x4B,0x4C,0x0F, 0x6C,0xC4,0x16,0x59,
    },
//
//   The generator generates a prime-order subgroup of size:
//
    .q = {
        0x8C,0xF8,0x36,0x42, 0xA7,0x09,0xA0,0x97, 0xB4,0x47,0x99,0x76, 0x40,0x12,0x9D,0xA2, 0x99,0xB1,0xA4,0x7D, 0x1E,0xB3,0x75,0x0B,
        0xA3,0x08,0xB0,0xFE, 0x64,0xF5,0xFB,0xD3,
    }
};

#endif /* _CORECRYPTO_RFC5114DHGROUPS_H_ */
