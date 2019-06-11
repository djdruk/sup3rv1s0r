//
//  keybag.c
//  sup3rv1s0r
//
//  Created by Samantha Demi on 4/29/14.
//  Copyright (c) 2014 Samantha Demi. All rights reserved.
//

#ifndef sup3rv1s0r_keybag_c
#define sup3rv1s0r_keybag_c

#include "keybag.h"

#pragma clang diagnostic ignored "-Wpointer-sign"

#define kVERS 0x56455253
#define kTYPE 0x54595045
#define kUUID 0x55554944
#define kHMCK 0x484d434b
#define kWRAP 0x57524150
#define kSALT 0x53414c54
#define kITER 0x49544552
#define kCLAS 0x434c4153
#define kKTYP 0x4b545950
#define kWPKY 0x57504b59

struct keybag_block nuke_keybag[] = {
	{{be32toh(kVERS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kTYPE), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x01})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x44, 0x15, 0x16, 0xb5, 0x25, 0xfb, 0x4d, 0x38, 0xa5, 0xa7, 0xcc, 0x73, 0x2c, 0x1b, 0xad, 0xdf})},
	{{be32toh(kHMCK), be32toh(40)}, ((int8_t [40]){0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kSALT), be32toh(20)}, ((int8_t [20]){0xe5, 0xa7, 0xed, 0xce, 0x3a, 0x82, 0x28, 0x2e, 0xed, 0x59, 0x0f, 0x63, 0xe7, 0x43, 0x6b, 0x29, 0xc0, 0x9b, 0xd9, 0x11})},
	{{be32toh(kITER), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x27, 0x10})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x60, 0xb6, 0x0e, 0x7a, 0x0b, 0xec, 0x42, 0x99, 0x96, 0xb5, 0x04, 0x60, 0x12, 0x2f, 0xaf, 0x60})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x0b})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x4c, 0x00, 0x2c, 0x30, 0x5b, 0x6d, 0xbc, 0xb1, 0x6a, 0x34, 0xf7, 0x49, 0x0c, 0x0a, 0x61, 0x98, 0xdf, 0xfe, 0x1d, 0x8e, 0x7c, 0x68, 0xd1, 0x56, 0x80, 0x3c, 0xea, 0x02, 0xf8, 0xae, 0x7d, 0x73, 0xce, 0xce, 0x8e, 0x2a, 0x42, 0xbc, 0xd0, 0x1d})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x41, 0x9b, 0x74, 0xa2, 0x6a, 0xd5, 0x46, 0xe2, 0x8c, 0x46, 0x20, 0x5b, 0x17, 0xcd, 0x49, 0xeb})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x0a})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0xb5, 0xf8, 0x7a, 0x16, 0xec, 0x0c, 0xd2, 0x72, 0xd5, 0xb5, 0xd3, 0xb0, 0xf4, 0x42, 0x55, 0x1f, 0x22, 0x2d, 0x05, 0xaf, 0x09, 0x1c, 0x35, 0x9e, 0x28, 0xd7, 0x63, 0x33, 0x18, 0xe3, 0x17, 0x79, 0xc2, 0x63, 0xa2, 0xa5, 0x5a, 0xea, 0x7f, 0xed})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x7c, 0xde, 0x72, 0x04, 0xbe, 0x48, 0x4c, 0x1f, 0x95, 0x9c, 0x01, 0xe3, 0x9f, 0xd7, 0x99, 0x2b})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x09})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x16, 0x7c, 0x31, 0x72, 0xdd, 0x18, 0x85, 0x3b, 0xcd, 0x8a, 0x7b, 0x5b, 0x8d, 0x1b, 0x14, 0x7d, 0x18, 0xd4, 0x41, 0x04, 0x08, 0x7d, 0x11, 0xef, 0x30, 0xa4, 0xad, 0x8a, 0xdb, 0x23, 0x84, 0x33, 0xd1, 0x88, 0xa2, 0x4f, 0x8d, 0x5f, 0xcf, 0xf6})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0xa6, 0x9d, 0xfc, 0xaa, 0xe0, 0xd1, 0x48, 0x83, 0xa5, 0x90, 0x25, 0x60, 0xf1, 0xad, 0x53, 0xdb})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x08})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x7b, 0xee, 0x62, 0xb2, 0xab, 0xde, 0xb8, 0x01, 0x89, 0x60, 0x2c, 0x8b, 0x54, 0x87, 0xad, 0xad, 0x24, 0xe1, 0xf2, 0xa0, 0x4f, 0xb3, 0x21, 0x44, 0x2c, 0x5b, 0xc4, 0x45, 0xa7, 0x3f, 0xe8, 0x5a, 0xc0, 0x7a, 0xc3, 0x99, 0x4f, 0xef, 0xb1, 0x3e})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0xdf, 0xa7, 0x3e, 0x9c, 0xa5, 0x9b, 0x44, 0xbd, 0x89, 0xe0, 0x8d, 0x02, 0x8e, 0x1f, 0x73, 0x73})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x07})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x93, 0x2d, 0xbc, 0x3d, 0xca, 0x61, 0x04, 0xc1, 0x03, 0x6e, 0x00, 0x29, 0x7d, 0x75, 0xfd, 0x21, 0x2c, 0xfe, 0xf8, 0x76, 0x53, 0x47, 0x85, 0x4a, 0xb0, 0x5e, 0x7b, 0x7c, 0x4a, 0x06, 0x4f, 0x7a, 0x7c, 0x42, 0xab, 0x1c, 0xeb, 0x1b, 0x18, 0xb7})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0xc6, 0x08, 0x98, 0x36, 0x37, 0x54, 0x40, 0xcd, 0xbb, 0x31, 0xe9, 0x8d, 0xa4, 0xdc, 0xe1, 0xcf})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x06})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0xb5, 0x57, 0x8e, 0x30, 0xb4, 0xe6, 0x1e, 0x8e, 0x1a, 0xec, 0xcb, 0xf8, 0xc1, 0xb7, 0xea, 0x5f, 0x2e, 0x16, 0x6d, 0x74, 0x98, 0xf2, 0x22, 0x8f, 0x89, 0x84, 0x40, 0x7a, 0xb8, 0x44, 0xbe, 0x0e, 0x90, 0xea, 0xe3, 0x24, 0xb2, 0x9f, 0xc8, 0xed})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x1a, 0x53, 0x0a, 0x86, 0xd5, 0x17, 0x4b, 0x20, 0xb8, 0x88, 0xc5, 0xf1, 0x58, 0xa6, 0x81, 0x14})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x05})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x1a, 0xbd, 0xb3, 0x82, 0xac, 0x66, 0xc7, 0xe9, 0x91, 0x51, 0x5c, 0x9e, 0x71, 0xaa, 0x0f, 0xb9, 0x0c, 0x0f, 0xc3, 0xec, 0x46, 0xbd, 0xec, 0x6a, 0xbb, 0x33, 0x3f, 0xb0, 0x60, 0x35, 0xb8, 0xd5, 0x0d, 0x78, 0x74, 0x81, 0xfe, 0xef, 0x76, 0xda})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x20, 0xfd, 0x93, 0xf8, 0x6d, 0x19, 0x43, 0x29, 0x80, 0xa2, 0xda, 0x8a, 0x3e, 0x3a, 0x47, 0x96})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x04})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x02})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0xbd, 0xd7, 0x69, 0xac, 0xb6, 0x1d, 0x32, 0xd6, 0x75, 0x0c, 0x63, 0xd3, 0x28, 0x94, 0x82, 0x58, 0x5d, 0xc2, 0x62, 0x98, 0xa5, 0x9a, 0xc7, 0x85, 0xb2, 0xec, 0x7d, 0x25, 0x67, 0x54, 0x46, 0x63, 0x7d, 0xdd, 0x9a, 0x97, 0x59, 0x71, 0xe1, 0xae})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0xee, 0x23, 0xe2, 0x36, 0x10, 0x90, 0x4d, 0xc4, 0x80, 0x33, 0x88, 0xad, 0xae, 0x0e, 0x40, 0xcd})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x03})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x02})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x2f, 0x7e, 0x5c, 0x9b, 0x5c, 0x84, 0x7b, 0x01, 0xa8, 0xd4, 0x5b, 0x62, 0x0b, 0x21, 0x2f, 0x6f, 0xcb, 0x16, 0xf8, 0xc1, 0x02, 0xa4, 0x6e, 0x62, 0x06, 0x40, 0xfb, 0x50, 0x21, 0x9e, 0xfe, 0xc3, 0x68, 0x2a, 0x6a, 0xc1, 0x3b, 0xb2, 0x60, 0xe7})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x9f, 0x7c, 0x51, 0xbc, 0x4f, 0xb4, 0x4e, 0xca, 0x9b, 0x13, 0xa8, 0x8f, 0xc4, 0xd2, 0x14, 0xc1})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x02})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x02})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0x17, 0xf9, 0x8a, 0xf1, 0x9e, 0x18, 0x03, 0x19, 0x71, 0xcb, 0xa7, 0x6b, 0x42, 0x06, 0xbe, 0x0e, 0x5e, 0xab, 0x6f, 0xf6, 0x21, 0x67, 0xb9, 0xeb, 0xe6, 0x94, 0xd8, 0xb2, 0x82, 0x09, 0xc9, 0x64, 0x63, 0xef, 0x94, 0x31, 0xf4, 0x76, 0xdd, 0x53})},
	{{be32toh(kUUID), be32toh(16)}, ((int8_t [16]){0x70, 0x87, 0x70, 0x5e, 0x36, 0xa3, 0x46, 0xee, 0xa2, 0x19, 0x05, 0xea, 0x37, 0xa3, 0xf5, 0xbc})},
	{{be32toh(kCLAS), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x01})},
	{{be32toh(kWRAP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x02})},
	{{be32toh(kKTYP), be32toh(4)}, ((int8_t [4]){0x00, 0x00, 0x00, 0x00})},
	{{be32toh(kWPKY), be32toh(40)}, ((int8_t [40]){0xbb, 0x60, 0x73, 0x57, 0x01, 0x06, 0xc7, 0xf5, 0x10, 0xdf, 0x17, 0xf9, 0xce, 0x2c, 0xd0, 0x18, 0xcb, 0x59, 0xad, 0x6a, 0x71, 0x0c, 0x4b, 0x77, 0x2e, 0x00, 0xbd, 0x09, 0x6f, 0x96, 0x07, 0xdf, 0x88, 0x41, 0x5b, 0x45, 0x1c, 0x82, 0xa1, 0xf9})}
};

#define BYTES(a) (a&0xff000000)>>24,(a&0x00ff0000)>>16,(a&0x0000ff00)>>8,(a&0x000000ff)

struct keybag * ParseKeybag(BufferRef bag) {
	struct keybag * keybag = calloc(1, sizeof(struct keybag));
	if (bag) {
		keybag->block = calloc(1, sizeof(struct keybag_block));
		uint64_t offset = 0;
		while (offset < bag->length) {
			keybag->block = realloc(keybag->block, sizeof(struct keybag_block)*(keybag->block_count+1));
			memset(&(keybag->block[keybag->block_count]), 0, sizeof(struct keybag_block));
			memcpy(&(keybag->block[keybag->block_count].header), &(bag->data[offset]), sizeof(struct keybag_block_header));
			keybag->block[keybag->block_count].header.type = be32toh(keybag->block[keybag->block_count].header.type);
			keybag->block[keybag->block_count].header.length = be32toh(keybag->block[keybag->block_count].header.length);
			offset += sizeof(struct keybag_block_header);
			if (keybag->block[keybag->block_count].header.length > 0) {
				keybag->block[keybag->block_count].data = calloc(keybag->block[keybag->block_count].header.length, sizeof(char));
				memcpy(keybag->block[keybag->block_count].data, &(bag->data[offset]), keybag->block[keybag->block_count].header.length);
			}
			offset += keybag->block[keybag->block_count].header.length;
			keybag->block_count++;
		}
	}
	return keybag;
}

#endif