/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ST7796_SPI__H_
#define YSS_MOD_TFT_LCD_DRIVER_ST7796_SPI__H_

#include <drv/Gpio.h>
#include <drv/Spi.h>
#include "ST6201_with_Brush_RGB565.h"

class ST6201_qspi_with_Brush_RGB565 : public ST6201_with_Brush_RGB565
{
public:
	typedef struct 
	{
		Quadspi &dev;
		pin_t reset;
		pin_t cs;
	}config_t;

	ST6201_qspi_with_Brush_RGB565(void);

	virtual error_t initialize(config_t config) = 0;

	void setSpiSpecification(const Spi::specification_t &spec);

	void reset(void); // virtual 0

  protected:
	Quadspi *mDev;
	pin_t mRstPin;
	pin_t mCsPin;
	const Spi::specification_t *mSpec;

	void setConfig(const config_t &config);

	virtual void sendCmd(uint8_t cmd); // pure

	virtual void sendCmd(uint8_t cmd, uint8_t data); // pure
	
	virtual void sendCmd(uint8_t cmd, uint8_t *data, uint32_t count); // pure

	virtual void sendData(uint8_t *data, uint32_t count); // pure

	virtual void sendData(uint16_t *data, uint32_t count); // pure

	virtual void sendData(uint32_t *data, uint32_t count); // pure
	
	virtual void enable(void);

	virtual void disable(void);

	void read(uint8_t cmd, uint8_t &des);
};

#endif

