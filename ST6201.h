/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9341__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9341__H_

#include <yss/instance.h>
#include "TurtleShip/TftLcdDriver.h"

class Rectangular;

class ST6201 : public TftLcdDriver
{
public :
	ST6201(void);

	void setDirection(bool xMirror, bool yMirror, bool rotate);

	void setWindows(int16_t x, int16_t y, uint16_t width = 1, uint16_t height = 1);

	void setWindows(Rectangular rect);

	virtual void enable(void) = 0;

	virtual void disable(void) = 0;

	virtual void sendCmd(uint8_t cmd) = 0;

	virtual void sendCmd(uint8_t cmd, uint8_t data) = 0;

	virtual void sendCmd(uint8_t cmd, uint8_t *data, uint32_t count) = 0;

	virtual void sendData(uint8_t *data, uint32_t count) = 0;

	virtual void sendData(uint16_t *data, uint32_t count) = 0;

	virtual void sendData(uint32_t *data, uint32_t count) = 0;
protected :
	typedef enum
	{
		CMD_NOP = 0x00,
		RD_SYSID = 0x04,
		RD_STATE = 0x09,
		RD_DISP = 0x0A,
		RD_MADCTL = 0x0B,
		RD_IM = 0x0D,
		RD_SM = 0x0E,
		SLPIN = 0x10,
		SLPOUT = 0x11,
		PTLON = 0x12,
		NORMAL = 0x13,
		INVOFF = 0x20,
		INVON = 0x21,
		DISPOFF = 0x28,
		DISPON = 0x29,
		COL_ADR = 0x2A,
		ROW_ADR = 0x2B,
		PTL_ADR = 0x30,
		SCROLL_ADR = 0x33,
		TEOFF = 0x34,
		TEON = 0x35,
		MACTL = 0x36,
		VSCSAD = 0x37,
		IDMOFF = 0x38,
		IDMON = 0x39,
		COLMOD = 0x3A,
		MACTL_USR = 0x40,
		BUS_WD = 0x41,
		QSPI_DCTL = 0x43,
		VBP = 0x44,
		VFP = 0x45,
		FSM_HBP_O = 0x46,
		FSM_HFP_O = 0x47,
		HSM_HBP_E = 0x48,
		HSM_HFP_E = 0x49,
		SCAN_VRES = 0x4A,
		GATE_SCAN = 0x50,
		GATE_SETTING = 0x51,
		PANEL_CTRL = 0x55,
		PTL_DAT = 0x68,
		LVD_SET = 0x6E,
		USR_GVDD = 0x6F,
		OSC = 0x73,
		USR_GVCL = 0x78,
		USR_VGSP = 0x7A,
		GVREF2V = 0x7C,
		VDDS_TRIM = 0x7D,
		GAMMA_P_SEL = 0x80,
		GAMMA_N_SEL = 0xA0,
		BIAS_VBG = 0xC0,
		MV_CLP = 0xC1,
		VGH_CLP = 0xC2,
		VGL_CLP = 0xC3,
		MV_TD = 0xC4,
		MV_SS_CTRL = 0xC5,
		RATIO_CTRL = 0xC6,
		MV_PUMP_CLK = 0xC7,
		HV_PUMP_CLK = 0xC8,
		MV_CLK_CLP = 0xC9,
		RD_SYSID2 = 0xDA,
		INTF_PORCH = 0xE3,
		DVDD_TRIM = 0xE5,
		ESD_CTRL = 0xE6,
		TE_CTRL = 0xE7,
		OTP_CTRL = 0xF1,
	}cmd_t;

	bool mRotateFlag;
};

#endif

