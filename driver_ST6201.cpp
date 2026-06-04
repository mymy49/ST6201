/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#include "ST6201.h"
#include "TurtleShip/Area.h"

ST6201::ST6201(void)
{

}
void ST6201::setWindow(Area rect)
{
	uint8_t data[4];
	int32_t buf;
	
	buf = rect.getPosition().getX();
	data[0] = (buf >> 8) & 0x01;
	data[1] = buf & 0xFF;

	buf += rect.getSize().getWidth() - 1;
	data[2] = (buf >> 8) & 0x01;
	data[3] = buf & 0xFF;
	sendCmd(COL_ADR, data, 4);

	buf = rect.getPosition().getY();
	data[0] = (buf >> 8) & 0x01;
	data[1] = buf & 0xFF;

	buf += rect.getSize().getHeight() - 1;
	data[2] = (buf >> 8) & 0x01;
	data[3] = buf & 0xFF;
	sendCmd(ROW_ADR, data, 4);
}

void ST6201::setWindows(int16_t x, int16_t y, uint16_t width, uint16_t height)
{
	uint8_t data[4];

	data[0] = (x >> 8) & 0x01;
	data[1] = x & 0xFF;
	
	width += x - 1;
	data[2] = (width >> 8) & 0x01;
	data[3] = width & 0xFF;
	sendCmd(COL_ADR, data, 4);

	data[0] = (y >> 8) & 0x01;
	data[1] = y & 0xFF;
	
	height += y - 1;
	data[2] = (height >> 8) & 0x01;
	data[3] = height & 0xFF;
	sendCmd(ROW_ADR, data, 4);
}

void ST6201::setDirection(bool xMirror, bool yMirror, bool rotate)
{
	//enable();

	//int8_t memAccCtrl[] = {0x00};
	//if(rotate)
	//{
	//	memAccCtrl[0] |= 0x20;

	//	if(xMirror)
	//		memAccCtrl[0] |= 0x80;
	//	if(yMirror)
	//		memAccCtrl[0] |= 0x40;
	//}
	//else
	//{
	//	if(xMirror)
	//		memAccCtrl[0] |= 0x40;
	//	if(yMirror)
	//		memAccCtrl[0] |= 0x80;
	//}

	//mRotateFlag = rotate;

	//updateLcdSize();

	//sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));
	//disable();
}

