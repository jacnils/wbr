/*
Copyright (c) 2010 - Wii Banner Player Project

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#ifndef WII_BNR_WRAP_GX_
#define WII_BNR_WRAP_GX_

#include <cstring>

#define 	GX_MAX_TEVREG   4
#define 	GX_TEVPREV   0
#define 	GX_TEVREG0   1
#define 	GX_TEVREG1   2
#define 	GX_TEVREG2   3

typedef float f32;

// watev
struct GXTexObj
{
	GXTexObj()
	{
		memset(val, 0, sizeof(val));
	};

	uint32_t 	val [8];
};

struct GXTlutObj
{
	GXTlutObj()
	{
		memset(val, 0, sizeof(val));
	};

	uint32_t val[8];
};

struct GXColor
{
	uint8_t r, g, b, a;
};

struct GXColorS10
{
	int16_t r, g, b, a;
};

typedef void GXFifoObj;

GXFifoObj * 	GX_Init (void *base, uint32_t size);

//void 	GX_SetViewport (f32 xOrig, f32 yOrig, f32 wd, f32 ht, f32 nearZ, f32 farZ);

uint32_t 	GX_GetTexBufferSize (uint16_t wd, uint16_t ht, uint32_t fmt, uint8_t mipmap, uint8_t maxlod);

void 	GX_InitTlutObj (GXTlutObj *obj, void *lut, uint8_t fmt, uint16_t entries);
void 	GX_LoadTlut (GXTlutObj *obj, uint32_t tlut_name);
void 	GX_InitTexObjTlut (GXTexObj *obj, uint32_t tlut_name);

void 	GX_InitTexObj (GXTexObj *obj, void *img_ptr, uint16_t wd, uint16_t ht, uint8_t fmt, uint8_t wrap_s, uint8_t wrap_t, uint8_t mipmap);
void 	GX_InitTexObjWrapMode (GXTexObj *obj, uint8_t wrap_s, uint8_t wrap_t);
void 	GX_InitTexObjFilterMode (GXTexObj *obj, uint8_t minfilt, uint8_t magfilt);

void 	GX_LoadTexObj (GXTexObj *obj, uint8_t mapid);

void 	GX_SetBlendMode (uint8_t type, uint8_t src_fact, uint8_t dst_fact, uint8_t op);
void 	GX_SetAlphaCompare (uint8_t comp0, uint8_t ref0, uint8_t aop, uint8_t comp1, uint8_t ref1);

void 	GX_SetTevOrder (uint8_t tevstage, uint8_t texcoord, uint32_t texmap, uint8_t color);
void 	GX_SetTevSwapMode (uint8_t tevstage, uint8_t ras_sel, uint8_t tex_sel);
void 	GX_SetTevSwapModeTable (uint8_t table, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

void 	GX_SetTevIndirect (uint8_t tevstage, uint8_t indtexid, uint8_t format, uint8_t bias, uint8_t mtxid,
	uint8_t wrap_s, uint8_t wrap_t, uint8_t addprev, uint8_t utclod, uint8_t a);

void 	GX_SetTevKAlphaSel (uint8_t tevstage, uint8_t sel);
void 	GX_SetTevKColorSel (uint8_t tevstage, uint8_t sel);

void 	GX_SetTevAlphaIn (uint8_t tevstage, uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void 	GX_SetTevAlphaOp (uint8_t tevstage, uint8_t tevop, uint8_t tevbias, uint8_t tevscale, uint8_t clamp, uint8_t tevregid);

void 	GX_SetTevColorIn (uint8_t tevstage, uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void 	GX_SetTevColorOp (uint8_t tevstage, uint8_t tevop, uint8_t tevbias, uint8_t tevscale, uint8_t clamp, uint8_t tevregid);

void 	GX_SetTevColorS10 (uint8_t tev_regid, GXColorS10 color);
void 	GX_SetTevKColor (uint8_t tev_regid, GXColor color);

void 	GX_SetNumTevStages (uint8_t num);

#endif
