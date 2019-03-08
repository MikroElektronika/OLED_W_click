/*
Example for OLED W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration CEC :

    MCU              : CEC1702
    Dev. Board       : Clicker 2 for CEC1702
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
line31Find.sh: line 6: pause: command not found
./ARM/KINETIS/KINETIS_SPI/Click_OLED_W_KINETIS.c
/*
Example for OLED_W Click

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
}line31Find.sh: line 6: pause: command not found
./ARM/MSP/MSP_SPI/Click_OLED_W_MSP.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration MSP :

    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
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
}line31Find.sh: line 6: pause: command not found
./ARM/STM/STM_SPI/Click_OLED_W_STM.c
/*
Example for OLED W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration STM32 :

    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
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
}line31Find.sh: line 6: pause: command not found
./ARM/TIVA/TIVA_SPI/Click_OLED_W_TIVA.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration TIVA :

    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
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
}line31Find.sh: line 6: pause: command not found
./AVR/SPI/Click_OLED_W_AVR.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration AVR :

    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7
    AVR Compiler ver : v7.0.1.0

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
}line31Find.sh: line 6: pause: command not found
./DSPIC/SPI/Click_OLED_W_DSPIC.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration dsPIC :

    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.0.1.0

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
}line31Find.sh: line 6: pause: command not found
./FT90x/SPI/Click_OLED_W_FT90x.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration FT90x :

    MCU                : FT900
    Dev. Board         : EasyFT90x v7
    FT90x Compiler ver : v2.2.1.0

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
}line31Find.sh: line 6: pause: command not found
./PIC/SPI/Click_OLED_W_PIC.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration PIC :

    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

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
}line31Find.sh: line 6: pause: command not found
./PIC32/SPI/Click_OLED_W_PIC32.c
/*
Example for OLED_W Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration PIC32 :

    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

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

