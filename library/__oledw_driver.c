/*
    __oledw_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__oledw_driver.h"
#include "__oledw_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __OLEDW_DRV_I2C__
static uint8_t _slaveAddress;
#endif

uint8_t OLED_W_LCDWIDTH = 96;
uint8_t OLED_W_LCDHEIGHT = 39;
uint8_t OLED_W_DISPLAYOFF = 0xAE;
uint8_t OLED_W_SETDISPLAYCLOCKDIV = 0xD5;
uint8_t OLED_W_SETMULTIPLEX = 0xA8;
uint8_t OLED_W_SETDISPLAYOFFSET = 0xD3;
uint8_t OLED_W_SETSTARTLINE = 0x40;
uint8_t OLED_W_CHARGEPUMP = 0x8D;
uint8_t OLED_W_SETSEGMENTREMAP = 0xA1;
uint8_t OLED_W_SEGREMAP = 0xA0;
uint8_t OLED_W_COMSCANDEC = 0xC8;
uint8_t OLED_W_SETCOMPINS = 0xDA;
uint8_t OLED_W_SETCONTRAST = 0x81;
uint8_t OLED_W_SETPRECHARGE = 0xD9;
uint8_t OLED_W_SETVCOMDETECT = 0xDB;
uint8_t OLED_W_DISPLAYALLON_RESUME = 0xA4;
uint8_t OLED_W_NORMALDISPLAY = 0xA6;
uint8_t OLED_W_DISPLAYON = 0xAF;
uint8_t OLED_W_DISPLAYALLON = 0xA5;
uint8_t OLED_W_INVERTDISPLAY = 0xA7;
uint8_t OLED_W_SETLOWCOLUMN = 0x00;
uint8_t OLED_W_SETHIGHCOLUMN = 0x10;
uint8_t OLED_W_MEMORYMODE = 0x20;
uint8_t OLED_W_COLUMNADDR = 0x21;
uint8_t OLED_W_PAGEADDR = 0x22;
uint8_t OLED_W_COMSCANINC = 0xC0;
uint8_t OLED_W_EXTERNALVCC = 0x1;
uint8_t OLED_W_SWITCHCAPVCC = 0x2;
uint8_t OLED_W_ACTIVATE_SCROLL = 0x2F;
uint8_t OLED_W_DEACTIVATE_SCROLL = 0x2E;
uint8_t OLED_W_SET_VERTICAL_SCROLL_AREA = 0xA3;
uint8_t OLED_W_RIGHT_HORIZONTAL_SCROLL = 0x26;
uint8_t OLED_W_LEFT_HORIZONTAL_SCROLL = 0x27;
uint8_t OLED_W_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL = 0x29;
uint8_t OLED_W_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL = 0x2A;
uint8_t OLED_W_ADDR_COMMAND = 0x3C;
uint8_t OLED_W_ADDR_DATA = 0x3D;

static uint8_t OLED_W_SPI_PROTO = 0;
static uint8_t OLED_W_I2C_PROTO = 1;
/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */


/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */


/* --------------------------------------------------------- PUBLIC FUNCTIONS */

static uint8_t dirverUsed;

#ifdef   __OLEDW_DRV_SPI__

void oledw_spiDriverInit(T_OLEDW_P gpioObj, T_OLEDW_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
    
    dirverUsed = OLED_W_SPI_PROTO;

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __OLEDW_DRV_I2C__

void oledw_i2cDriverInit(T_OLEDW_P gpioObj, T_OLEDW_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    dirverUsed = OLED_W_I2C_PROTO;
    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __OLEDW_DRV_UART__

void oledw_uartDriverInit(T_OLEDW_P gpioObj, T_OLEDW_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

void oledw_sendCommand(uint8_t wData)
{
    uint8_t reg_data[2];
    if (dirverUsed == OLED_W_SPI_PROTO)
    {
        hal_gpio_csSet(0);
        hal_gpio_pwmSet(0);
        hal_spiWrite(&wData,1);
        hal_gpio_csSet(1);
    }
    else if (dirverUsed == OLED_W_I2C_PROTO)
    {
        hal_gpio_pwmSet(0);
        reg_data[0] = 0b0000000;
        reg_data[1] = wData;
        hal_i2cStart();
        hal_i2cWrite(OLED_W_ADDR_COMMAND,reg_data,2,END_MODE_STOP);
    }
}

void oledw_sendData(uint8_t wData)
{
    uint8_t reg_data[2];
    if (dirverUsed == OLED_W_SPI_PROTO)
    {
        hal_gpio_csSet(0);
        hal_gpio_pwmSet(1);
        hal_spiWrite(&wData,1);
        hal_gpio_csSet(1);

    }
    else if (dirverUsed == OLED_W_I2C_PROTO)
    {
      hal_gpio_pwmSet(1);
      reg_data[0] = 0b1100000;
      reg_data[1] = wData;
      hal_i2cStart();
      hal_i2cWrite(OLED_W_ADDR_DATA,reg_data,2,END_MODE_STOP);
    }
}
void oledw_init()
{
    uint8_t counter=0;

    hal_gpio_rstSet(0);

    while(counter<10) 
    {
        Delay_100ms();
        counter++;
    }
    
    counter =0;
    hal_gpio_rstSet(1);

    while(counter<10) 
    {
        Delay_100ms();
        counter++;
    }

    oledw_sendCommand(OLED_W_DISPLAYOFF);             //0xAE Set OLED Display Off
    oledw_sendCommand(OLED_W_SETDISPLAYCLOCKDIV);     //0xD5 Set Display Clock Divide Ratio/Oscillator Frequency
    oledw_sendCommand(0x80);
    oledw_sendCommand(OLED_W_SETMULTIPLEX);           //0xA8 Set Multiplex Ratio
    oledw_sendCommand(0x27);
    oledw_sendCommand(OLED_W_SETDISPLAYOFFSET);       //0xD3 Set Display Offset
    oledw_sendCommand(0x00);
    oledw_sendCommand(OLED_W_SETSTARTLINE);           //0x40 Set Display Start Line
    oledw_sendCommand(OLED_W_CHARGEPUMP);             //0x8D Set Charge Pump
    oledw_sendCommand(0x14);                           //0x14 Enable Charge Pump
    oledw_sendCommand(OLED_W_COMSCANDEC);             //0xC8 Set COM Output Scan Direction
    oledw_sendCommand(OLED_W_SETCOMPINS);             //0xDA Set COM Pins Hardware Configuration
    oledw_sendCommand(0x12);
    oledw_sendCommand(OLED_W_SETCONTRAST);            //0x81 Set Contrast Control
    oledw_sendCommand(0xAF);
    oledw_sendCommand(OLED_W_SETPRECHARGE);           //0xD9 Set Pre-Charge Period
    oledw_sendCommand(0x25);
    oledw_sendCommand(OLED_W_SETVCOMDETECT);          //0xDB Set VCOMH Deselect Level
    oledw_sendCommand(0x20);
    oledw_sendCommand(OLED_W_DISPLAYALLON_RESUME);    //0xA4 Set Entire Display On/Off
    oledw_sendCommand(OLED_W_NORMALDISPLAY);          //0xA6 Set Normal/Inverse Display
    oledw_sendCommand(OLED_W_DISPLAYON);              //0xAF Set OLED Display On
}
//Set page adress for Page Addressing Mode
void oledw_setPage(uint8_t addr)
{
    addr = 0xb0|addr;
    oledw_sendCommand(addr);
}

//Set column adress for Page Addressing Mode
void oledw_setColumn(uint8_t addr)
{
    oledw_sendCommand((0x10|(addr>>4)));
    oledw_sendCommand((0x0f&addr));
}
//Display picture for Page Addressing Mode
void oledw_displayPicture(const uint8_t *pic)
{
    uint8_t i;
    uint8_t j;
    uint8_t num;
    num=0;
    for(i=0;i<0x05;i++)
    {
        oledw_setPage(i);
        // Set_Column_Address(0x00);
        oledw_sendCommand(0x10);
        oledw_sendCommand(0x40);
        for(j=0;j<0x60;j++)
        {
            oledw_sendData(pic[i*0x60+j]);
        }
    }
}
void oledw_setContrast(uint8_t temp)
{
    oledw_sendCommand(OLED_W_SETCONTRAST);                 // 0x81   Set Contrast Control
    oledw_sendCommand(temp);                                // contrast step 1 to 256
}
void oledw_scrollRight(uint8_t startPageAddress, uint8_t endPageAddress)
{
    oledw_sendCommand(OLED_W_RIGHT_HORIZONTAL_SCROLL);      // 0x26  Right Horizontal scroll
    oledw_sendCommand(0X00);                                 // dummy byte
    oledw_sendCommand(startPageAddress);                    // define start page address
    oledw_sendCommand(0X00);                                 // Set time interval between each scroll
    oledw_sendCommand(endPageAddress);                      // Define end page address
    oledw_sendCommand(0X00);                                 // dummy byte
    oledw_sendCommand(0XFF);                                 // dummy byte
    oledw_sendCommand(OLED_W_ACTIVATE_SCROLL);
}
void oledw_scrollLeft(uint8_t startPageAddress, uint8_t endPageAddress)
{
    oledw_sendCommand(OLED_W_LEFT_HORIZONTAL_SCROLL);       // 0x27  Right Horizontal scroll
    oledw_sendCommand(0X00);                                 // dummy byte
    oledw_sendCommand(startPageAddress);                                    // define start page address
    oledw_sendCommand(0X00);                                 // Set time interval between each scroll
    oledw_sendCommand(endPageAddress);                                    // Define end page address
    oledw_sendCommand(0X00);                                 // dummy byte
    oledw_sendCommand(0XFF);                                 // dummy byte
    oledw_sendCommand(OLED_W_ACTIVATE_SCROLL);              // 0x2F Activate scroll
}
void oledw_scrollDiagright(uint8_t startPageAddress, uint8_t endPageAddress)
{
    oledw_sendCommand(OLED_W_SET_VERTICAL_SCROLL_AREA);              // 0xA3 Set Vertical Scroll Area
    oledw_sendCommand(0X00);                                          // Set No. of rows in top fixed area
    oledw_sendCommand(OLED_W_LCDHEIGHT);                             // Set No. of rows in scroll area
    oledw_sendCommand(OLED_W_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);  // 0x29 Vertical and Right Horizontal Scroll
    oledw_sendCommand(0X00);                                          // dummy byte
    oledw_sendCommand(startPageAddress);                                             // Define start page address
    oledw_sendCommand(0X00);                                          // Set time interval between each scroll
    oledw_sendCommand(endPageAddress);                                             // Define end page address
    oledw_sendCommand(0X01);                                          // Vertical scrolling offset
    oledw_sendCommand(OLED_W_ACTIVATE_SCROLL);                       // 0x2F Activate scroll
}
void oledw_scrollDiagleft(uint8_t startPageAddress, uint8_t endPageAddress)
{
    oledw_sendCommand(OLED_W_SET_VERTICAL_SCROLL_AREA);              // 0xA3 Set Vertical Scroll Area
    oledw_sendCommand(0X00);                                          // Set No. of rows in top fixed area
    oledw_sendCommand(OLED_W_LCDHEIGHT);                             // Set No. of rows in scroll area
    oledw_sendCommand(OLED_W_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);   // 0x2A Vertical and Right Horizontal Scroll
    oledw_sendCommand(0X00);                                          // dummy byte
    oledw_sendCommand(startPageAddress);                                             // Define start page address
    oledw_sendCommand(0X00);                                          // Set time interval between each scroll
    oledw_sendCommand(endPageAddress);                                             // Define end page address
    oledw_sendCommand(0X01);                                          // Vertical scrolling offset
    oledw_sendCommand(OLED_W_ACTIVATE_SCROLL);                       // 2F Activate scroll
}
void oledw_stopScroll()
{
    oledw_sendCommand(0x2E);          //0x2E deactivate scroll
}


/* ----------------------------------------------------------- IMPLEMENTATION */







/* -------------------------------------------------------------------------- */
/*
  __oledw_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */
