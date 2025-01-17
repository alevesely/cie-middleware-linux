#include "definitions.h"
#include "../Util/Array.h"


BYTE ExtAuth_PrivExp[] = { 
	0x18, 0x6B, 0x31, 0x48, 0x8C, 0x25, 0xDC, 0xF8, 0x5D, 0x95, 0x3D, 0x36, 0x30, 0xC0, 0xD0, 0x73,
	0xBA, 0x1C, 0x6A, 0xA2, 0x45, 0x81, 0xAD, 0x25, 0x4F, 0x3B, 0x67, 0x19, 0xC5, 0xD7, 0x2C, 0xCA,
	0x3E, 0x5C, 0xDC, 0x5A, 0x1E, 0x53, 0x16, 0x57, 0x8D, 0x75, 0x95, 0x4F, 0xF7, 0x3B, 0x23, 0x7B,
	0x53, 0x2C, 0x9F, 0x8D, 0xE4, 0xA2, 0xC4, 0xC9, 0x11, 0x38, 0x5A, 0x23, 0xE6, 0x3E, 0x33, 0xE4,
	0x7E, 0xE4, 0x5E, 0x66, 0xEF, 0xD4, 0x9B, 0x18, 0xE0, 0x2C, 0xFF, 0x87, 0x59, 0x8C, 0x39, 0x10,
	0x9E, 0x8F, 0x86, 0xA6, 0x6B, 0xC3, 0x30, 0x24, 0x9C, 0xE3, 0xFC, 0xAD, 0x65, 0x5D, 0xCD, 0xBF,
	0x98, 0xC9, 0xC5, 0xE4, 0x79, 0x32, 0x1A, 0xF5, 0x3B, 0x51, 0x7D, 0x04, 0x10, 0x61, 0x88, 0x0A,
	0x64, 0x7B, 0xBE, 0x0F, 0xF8, 0x13, 0x68, 0x34, 0x70, 0xE6, 0xC5, 0x00, 0x94, 0xCE, 0x81, 0xD0,
	0x64, 0xE2, 0x04, 0xE3, 0x51, 0xBD, 0x3A, 0xE0, 0xA7, 0x94, 0x7D, 0x8E, 0x91, 0xC3, 0xFD, 0x5C,
	0x0A, 0x15, 0x23, 0x3C, 0x34, 0x9A, 0x52, 0x15, 0xA4, 0xE6, 0x6E, 0x21, 0xC5, 0xD3, 0x34, 0x98,
	0xE7, 0x19, 0x91, 0xEA, 0x24, 0x47, 0x3B, 0x29, 0xF1, 0x47, 0x5F, 0x6F, 0xD9, 0xBE, 0x39, 0x96,
	0xE1, 0x9B, 0xD4, 0x74, 0xFA, 0xD1, 0xB4, 0x1E, 0xA0, 0xDC, 0xD2, 0xFC, 0x16, 0xC9, 0xBF, 0xFA,
	0x07, 0x1B, 0xFE, 0xC1, 0xB2, 0x24, 0x15, 0x18, 0x48, 0x11, 0xC1, 0x98, 0x5F, 0xBF, 0xE3, 0xE7,
	0xB4, 0xF4, 0x4A, 0x4B, 0x3C, 0x8D, 0xFA, 0xB4, 0xD9, 0x0C, 0xEC, 0xFC, 0x5E, 0x60, 0x8D, 0x67,
	0x3E, 0x67, 0x62, 0xC6, 0x2C, 0xB7, 0x98, 0x34, 0x12, 0x71, 0x14, 0x9B, 0xA6, 0x88, 0x16, 0x2E,
	0xC7, 0xD0, 0xE3, 0x46, 0x8F, 0x65, 0xA9, 0x4A, 0xB4, 0xAD, 0x1A, 0xB6, 0x7E, 0x37, 0xBF, 0xC1 };

ByteArray baExtAuth_PrivExp(ExtAuth_PrivExp, sizeof(ExtAuth_PrivExp));
