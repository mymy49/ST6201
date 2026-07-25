/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9341_WITH_BRUSH__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9341_WITH_BRUSH__H_

#include "ST6201.h"
#include "TurtleShip/BrushTftLcdRgb565LE.h"

class ST6201_with_Brush_RGB565 : public ST6201, public BrushTftLcdRgb565LE
{
public :
	ST6201_with_Brush_RGB565(void) __attribute__((optimize("-O1")));

	// Brush
	void drawDot(int16_t x, int16_t y) override  __attribute__((optimize("-O1")));

	void blendDot(int16_t x, int16_t y, uint8_t alpha) override __attribute__((optimize("-O1")));

	virtual void updateLcdSize(void) __attribute__((optimize("-O1")));

	void fillRectBase(int16_t x, int16_t y, uint16_t width, uint16_t height, Color color) override __attribute__((optimize("-O1")));

protected :
	uint32_t mBmpBufferSize;

	void fillDotArray(uint32_t offset, uint32_t count, Color color) override __attribute__((optimize("-O1")));

	void drawBitmapBase(Size canvasSize, Area targetCanvasArea, Position bitmapPos, const bitmap_t bitmap) override __attribute__((optimize("-O1")));

//	void drawBitmapBase(Position pos, const bitmap_t bitmap) override;

	void drawBitmapBase(Position pos, const bitmap_t bitmap) override __attribute__((optimize("-O1")));

private :
	void drawBitmapRgb565(Size canvasSize, Area targetCanvasArea, Position bitmapPos, const bitmap_t bitmap) __attribute__((optimize("-O1")));

	void drawBitmapArgb1555(Size canvasSize, Area targetCanvasArea, Position bitmapPos, const bitmap_t bitmap) __attribute__((optimize("-O1")));
};

#endif

