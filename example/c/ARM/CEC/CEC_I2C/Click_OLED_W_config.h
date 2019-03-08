#include "Click_OLED_W_types.h"

#ifdef  ENABLE_SPI
const uint32_t _OLEDW_SPI_CFG[ 3 ] = 
{ 
	1000000,  
	_SPI_MSB_FIRST, 
	_SPI_CLK_IDLE_LOW | 
	_SPI_SAMPLE_DATA_RISING_EDGE 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _OLEDW_I2C_CFG[ 1 ] = 
{ 
	_I2C_100KHZ 
};
#endif

#ifdef ENABLE_UART
const uint32_t _OLEDW_UART_CFG[ 4 ] = 
{
	9600, 
	_UART_8_BIT_DATA, 
    _UART_NOPARITY, 
    _UART_ONE_STOPBIT
};
#endif
