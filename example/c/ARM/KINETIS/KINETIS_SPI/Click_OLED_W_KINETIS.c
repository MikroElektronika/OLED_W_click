/*
Example for OLED W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration KINETIS :

    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization -  Initializes GPIO and I2C structures.
- Application Initialization - Configures the micro controller for communication
  and initializes the click board.
- Application Task - This section contains the main program that is executed
  showing a practiacal example on how to use the implemented functions.

*/

#include "Click_OLED_W_types.h"
#include "Click_OLED_W_config.h"

#include "resources.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_OLEDW_SPI_CFG[0] );
    Delay_ms( 100 );
}
void applicationInit()
{
    oledw_spiDriverInit( (T_OLEDW_P)&_MIKROBUS1_GPIO, (T_OLEDW_P)&_MIKROBUS1_SPI );
    oledw_init();
    Delay_ms(100);
}

void applicationTask()
{
    uint8_t i=0x00;
    oledw_displayPicture(&oledw[0]);
    Delay_ms(500);
    oledw_sendCommand(OLED_W_INVERTDISPLAY);
    Delay_ms(500);
    oledw_sendCommand(OLED_W_NORMALDISPLAY);
    Delay_ms(500);

    for(i=0xAF; i>0x00; i--){
        oledw_setContrast(i);
        Delay_ms(10);
    }
    for(i=0x00; i<0xAF; i++){
        oledw_setContrast(i);
        Delay_ms(10);
    }
    oledw_scrollRight(0x00, 0x05);
    Delay_ms(1000);
    oledw_stopScroll();
    oledw_displayPicture(&oledw[0]);

    oledw_scrollLeft(0x00, 0x05);
    Delay_ms(1000);
    oledw_stopScroll();
    oledw_displayPicture(&oledw[0]);

    oledw_scrollDiagright(0x00, 0x05);
    Delay_ms(1000);
    oledw_stopScroll();
    oledw_displayPicture(&oledw[0]);

    oledw_scrollDiagleft(0x00, 0x05);
    Delay_ms(1000);
    oledw_stopScroll();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
