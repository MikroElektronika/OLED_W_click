/*
    __oledw_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __oledw_driver.h
@brief    OLED_W Driver
@mainpage OLED_W Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   OLEDW
@brief      OLED_W Click Driver
@{

| Global Library Prefix | **OLEDW** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **mar 2018.**      |
| Developer             | **Dusan Poluga**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _OLEDW_H_
#define _OLEDW_H_

/** 
 * @macro T_OLEDW_P
 * @brief Driver Abstract type 
 */
#define T_OLEDW_P    const uint8_t*

/** @defgroup OLEDW_COMPILE Compilation Config */              /** @{ */

   #define   __OLEDW_DRV_SPI__                            /**<     @macro __OLEDW_DRV_SPI__  @brief SPI driver selector */
   #define   __OLEDW_DRV_I2C__                            /**<     @macro __OLEDW_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __OLEDW_DRV_UART__                           /**<     @macro __OLEDW_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup OLEDB_VAR Variables */                           /** @{ */
extern uint8_t OLED_W_LCDWIDTH;
extern uint8_t OLED_W_LCDHEIGHT;
extern uint8_t OLED_W_DISPLAYOFF;
extern uint8_t OLED_W_SETDISPLAYCLOCKDIV;
extern uint8_t OLED_W_SETMULTIPLEX;
extern uint8_t OLED_W_SETDISPLAYOFFSET;
extern uint8_t OLED_W_SETSTARTLINE;
extern uint8_t OLED_W_CHARGEPUMP;
extern uint8_t OLED_W_SETSEGMENTREMAP;
extern uint8_t OLED_W_SEGREMAP;
extern uint8_t OLED_W_COMSCANDEC;
extern uint8_t OLED_W_SETCOMPINS;
extern uint8_t OLED_W_SETCONTRAST;
extern uint8_t OLED_W_SETPRECHARGE;
extern uint8_t OLED_W_SETVCOMDETECT;
extern uint8_t OLED_W_DISPLAYALLON_RESUME;
extern uint8_t OLED_W_NORMALDISPLAY;
extern uint8_t OLED_W_DISPLAYON;
extern uint8_t OLED_W_DISPLAYALLON;
extern uint8_t OLED_W_INVERTDISPLAY;
extern uint8_t OLED_W_SETLOWCOLUMN;
extern uint8_t OLED_W_SETHIGHCOLUMN;
extern uint8_t OLED_W_MEMORYMODE;
extern uint8_t OLED_W_COLUMNADDR;
extern uint8_t OLED_W_PAGEADDR;
extern uint8_t OLED_W_COMSCANINC;
extern uint8_t OLED_W_EXTERNALVCC;
extern uint8_t OLED_W_SWITCHCAPVCC;
extern uint8_t OLED_W_ACTIVATE_SCROLL;
extern uint8_t OLED_W_DEACTIVATE_SCROLL;
extern uint8_t OLED_W_SET_VERTICAL_SCROLL_AREA;
extern uint8_t OLED_W_RIGHT_HORIZONTAL_SCROLL;
extern uint8_t OLED_W_LEFT_HORIZONTAL_SCROLL;
extern uint8_t OLED_W_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL;
extern uint8_t OLED_W_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL;
extern uint8_t OLED_W_ADDR_COMMAND;
extern uint8_t OLED_W_ADDR_DATA;

/*extern uint8_t OLEDB_SPI_PROTO;
extern uint8_t OLEDB_I2C_PROTO;*/

                                                                       /** @} */
/** @defgroup OLEDW_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup OLEDW_INIT Driver Initialization */              /** @{ */

#ifdef   __OLEDW_DRV_SPI__
void oledw_spiDriverInit(T_OLEDW_P gpioObj, T_OLEDW_P spiObj);
#endif
#ifdef   __OLEDW_DRV_I2C__
void oledw_i2cDriverInit(T_OLEDW_P gpioObj, T_OLEDW_P i2cObj, uint8_t slave);
#endif
#ifdef   __OLEDW_DRV_UART__
void oledw_uartDriverInit(T_OLEDW_P gpioObj, T_OLEDW_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void oledw_gpioDriverInit(T_OLEDW_P gpioObj);
                                                                       /** @} */
/** @defgroup OLEDB_FUNC Driver Functions */                   /** @{ */
void oledw_init(); /**< This function initializes the click board for communication. */
void oledw_sendCommand(uint8_t wData); /**< This function is used for sending commands to the OLED display. */
void oledw_sendData(uint8_t wData); /**< This function is used for sending data to the display. */
void oledw_setPage(uint8_t addr); /**< Set page adress for page addressing mode. */
void oledw_setColumn(uint8_t addr); /**< Set column adress for page addressing mode. */
void oledw_displayPicture(const uint8_t *pic); /**< Display picture for page addressing mode. */
void oledw_setContrast(uint8_t temp); /**< Set the display contrast level ( 0 to 255 ). */
void oledw_scrollRight(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display to the right. */
void oledw_scrollLeft(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display to the left. */
void oledw_scrollDiagright(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display diagonally to the right. */
void oledw_scrollDiagleft(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display diagonally to the right. */
void oledw_stopScroll(); /**< Stop the scrolling motion */
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_OLED_W_STM.c
    @example Click_OLED_W_TIVA.c
    @example Click_OLED_W_CEC.c
    @example Click_OLED_W_KINETIS.c
    @example Click_OLED_W_MSP.c
    @example Click_OLED_W_PIC.c
    @example Click_OLED_W_PIC32.c
    @example Click_OLED_W_DSPIC.c
    @example Click_OLED_W_AVR.c
    @example Click_OLED_W_FT90x.c
    @example Click_OLED_W_STM.mbas
    @example Click_OLED_W_TIVA.mbas
    @example Click_OLED_W_CEC.mbas
    @example Click_OLED_W_KINETIS.mbas
    @example Click_OLED_W_MSP.mbas
    @example Click_OLED_W_PIC.mbas
    @example Click_OLED_W_PIC32.mbas
    @example Click_OLED_W_DSPIC.mbas
    @example Click_OLED_W_AVR.mbas
    @example Click_OLED_W_FT90x.mbas
    @example Click_OLED_W_STM.mpas
    @example Click_OLED_W_TIVA.mpas
    @example Click_OLED_W_CEC.mpas
    @example Click_OLED_W_KINETIS.mpas
    @example Click_OLED_W_MSP.mpas
    @example Click_OLED_W_PIC.mpas
    @example Click_OLED_W_PIC32.mpas
    @example Click_OLED_W_DSPIC.mpas
    @example Click_OLED_W_AVR.mpas
    @example Click_OLED_W_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __oledw_driver.h

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

