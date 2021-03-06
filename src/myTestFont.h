
#ifndef myTestFont_H
#define myTestFont_H

#include "pyfont.h"

namespace myTestFont
{
    const uint8_t data[] =
    {
			0x00, 0x00, 0xBE, 0x06, 0x02, 0x06, 0x28, 0x7C, 0x28, 0x7C, 0x28, 0x2C, 0x7E, 0x34, 0x24, 0x10,
			0x08, 0x24, 0x60, 0x90, 0x90, 0x60, 0xF0, 0x10, 0x10, 0xE0, 0x90, 0x90, 0xFC, 0x06, 0x7C, 0x82,
			0x82, 0x7C, 0x28, 0x10, 0x28, 0x10, 0x10, 0x7C, 0x10, 0x10, 0xC0, 0x10, 0x10, 0x10, 0x80, 0xC0,
			0x38, 0x06, 0x7C, 0xB2, 0x9A, 0x7C, 0x08, 0x84, 0xFE, 0x80, 0xC4, 0xA2, 0x92, 0x8C, 0x44, 0x92,
			0x92, 0x6C, 0x1E, 0x10, 0x10, 0xFE, 0x9E, 0x92, 0x92, 0x62, 0x7C, 0x92, 0x92, 0x64, 0x02, 0xE2,
			0x12, 0x0E, 0x6C, 0x92, 0x92, 0x6C, 0x4C, 0x92, 0x92, 0x7C, 0x48, 0xC8, 0x10, 0x28, 0x44, 0x28,
			0x28, 0x28, 0x28, 0x44, 0x28, 0x10, 0x04, 0x02, 0xB2, 0x0C, 0x38, 0x44, 0x92, 0xAA, 0xF2, 0x84,
			0x78, 0xFC, 0x12, 0x12, 0xFC, 0xFE, 0x92, 0x92, 0x6C, 0x7C, 0x82, 0x82, 0x44, 0xFE, 0x82, 0x82,
			0x7C, 0xFE, 0x92, 0x92, 0x82, 0xFE, 0x12, 0x12, 0x02, 0x7C, 0x82, 0x92, 0xF4, 0xFE, 0x10, 0x10,
			0xFE, 0xFE, 0x42, 0x82, 0x82, 0x7E, 0xFE, 0x10, 0x28, 0xC6, 0xFE, 0x80, 0x80, 0x80, 0xFE, 0x04,
			0x08, 0x04, 0xFE, 0xFE, 0x04, 0x08, 0x10, 0xFE, 0x7C, 0x82, 0x82, 0x7C, 0xFE, 0x12, 0x12, 0x0C,
			0x7C, 0x82, 0xC2, 0xFC, 0xFE, 0x12, 0x12, 0xEC, 0x4C, 0x92, 0x92, 0x64, 0x02, 0x02, 0xFE, 0x02,
			0x02, 0x7E, 0x80, 0x80, 0x7E, 0x3E, 0x40, 0x80, 0x40, 0x3E, 0xFE, 0x40, 0x20, 0x40, 0xFE, 0xC6,
			0x28, 0x10, 0x28, 0xC6, 0x06, 0x08, 0xF0, 0x08, 0x06, 0xE2, 0x92, 0x8A, 0x86, 0xFE, 0x82, 0x82,
			0x06, 0x18, 0x60, 0x82, 0x82, 0xFE, 0x08, 0x04, 0x02, 0x04, 0x08, 0x80, 0x80, 0x80, 0x80, 0x06,
			0x70, 0x88, 0x88, 0xF8, 0xFE, 0x88, 0x88, 0x70, 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0xFE, 0x70,
			0xA8, 0xA8, 0x90, 0x10, 0xFC, 0x12, 0x70, 0x88, 0xA8, 0x68, 0xFE, 0x08, 0x08, 0xF0, 0xFA, 0x80,
			0x7A, 0xFE, 0x20, 0x50, 0x88, 0xFE, 0xF8, 0x08, 0xF8, 0x08, 0xF0, 0xF8, 0x08, 0x08, 0xF0, 0x70,
			0x88, 0x88, 0x70, 0xF8, 0x28, 0x28, 0x10, 0x10, 0x28, 0x28, 0xF8, 0xF0, 0x08, 0x08, 0x90, 0xA8,
			0xA8, 0x48, 0x08, 0x7E, 0x88, 0x78, 0x80, 0x80, 0xF8, 0x38, 0x40, 0x80, 0x40, 0x38, 0x78, 0x80,
			0x60, 0x80, 0x78, 0x88, 0x50, 0x20, 0x50, 0x88, 0x18, 0xA0, 0xA0, 0x78, 0xC8, 0xA8, 0xA8, 0x98,
			0x10, 0xFE, 0x82, 0xFE, 0x82, 0xFE, 0x10, 0x10, 0x08, 0x10, 0x20, 0x10, 0xFE, 0xFE, 0xFE, 0xFE,
			0xFE, 0x04, 0x0A, 0x04, 0xF8, 0x8C, 0x8E, 0x8C, 0xF8, 0x54, 0x38, 0x6C, 0x38, 0x54, 0xE0, 0xBE,
			0xE0, 0x70, 0x88, 0x88, 0xF8, 0x90, 0xFE, 0x4A, 0x4A, 0x34, 0x0C, 0x50, 0xA0, 0x50, 0x0C, 0xC0,
			0xB0, 0x98, 0xB0, 0xC0, 0x98, 0xE4, 0x02, 0x02, 0xE4, 0x98, 0x1C, 0x20, 0xF8, 0x24, 0x18, 0x08,
			0xF8, 0x08, 0xF8, 0x08
    };
    const uint16_t offsets[] =
    {
			0x000, 0x002, 0x003, 0x006, 0x00B, 0x00E, 0x012, 0x01D, 0x01E, 0x020, 0x022, 0x025, 0x02A, 0x02B, 0x02E, 0x02F,
			0x032, 0x036, 0x03A, 0x03E, 0x042, 0x046, 0x04A, 0x04E, 0x052, 0x056, 0x05A, 0x05B, 0x05C, 0x05F, 0x063, 0x066,
			0x06A, 0x071, 0x075, 0x079, 0x07D, 0x081, 0x085, 0x089, 0x08D, 0x091, 0x092, 0x096, 0x09A, 0x09E, 0x0A3, 0x0A8,
			0x0AC, 0x0B0, 0x0B4, 0x0B8, 0x0BC, 0x0C1, 0x0C5, 0x0CA, 0x0CF, 0x0D4, 0x0D9, 0x0DD, 0x0E0, 0x0E3, 0x0E6, 0x0EB,
			0x0EF, 0x0F0, 0x0F4, 0x0F8, 0x0FB, 0x0FF, 0x103, 0x106, 0x10A, 0x10E, 0x10F, 0x111, 0x115, 0x116, 0x11B, 0x11F,
			0x123, 0x127, 0x12B, 0x12E, 0x132, 0x135, 0x139, 0x13E, 0x143, 0x148, 0x14C, 0x150, 0x153, 0x154, 0x157, 0x15C,
			0x161, 0x164, 0x169, 0x16E, 0x171, 0x176, 0x17A, 0x17F, 0x184, 0x18A, 0x18F
    };
    const uint8_t sizes[] =
    {
			0x02, 0x01, 0x03, 0x05, 0x03, 0x04, 0x0B, 0x01, 0x02, 0x02, 0x03, 0x05, 0x01, 0x03, 0x01, 0x03,
			0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 0x01, 0x03, 0x04, 0x03, 0x04,
			0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 0x04, 0x04, 0x04, 0x05, 0x05, 0x04,
			0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x05, 0x05, 0x04, 0x03, 0x03, 0x03, 0x05, 0x04,
			0x01, 0x04, 0x04, 0x03, 0x04, 0x04, 0x03, 0x04, 0x04, 0x01, 0x02, 0x04, 0x01, 0x05, 0x04, 0x04,
			0x04, 0x04, 0x03, 0x04, 0x03, 0x04, 0x05, 0x05, 0x05, 0x04, 0x04, 0x03, 0x01, 0x03, 0x05, 0x05,
			0x03, 0x05, 0x05, 0x03, 0x05, 0x04, 0x05, 0x05, 0x06, 0x05, 0x05
    };

    const PyFont font(107, 32, data, offsets, sizes);
}

#endif //myTestFont_H
