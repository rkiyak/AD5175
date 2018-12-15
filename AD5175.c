/*
  @
  @   Date               :        10.08.2018 / Friday
  @
  @   Contact            :        Editing by Muhammet Rasit KIYAK                    @https://www.linkedin.com/in/mrstkyk/
  @                               mrstkyk@gmail.com 
  @
  @   Description        :        This Library for AD5175(Digital Potentiometer)
  @                               Dependency library is HAL for STM32 series (__STM32L4xx_HAL_I2C_H)
  @
*/

#include "AD5175.h"	
    
uint8_t AD5175_DeviceID=AD5175_DeviceID0;


/*	
   @Brief		Write contents of serial register data to RDAC
   @Description		There is 10 bit resolution this potentiometer.
   			Calculation is [(10000/1024)*SerialReg]= Resistor Value
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   			SerialReg		-> Step of potentiometer.10 bit resolution
   @Return value	None
 */
void AD5175_writeRDAC(I2C_HandleTypeDef i2c,uint16_t SerialReg)            	
{ 	w
	static uint8_t buf[2]                                         ;	
  	HAL_Delay(1)                                                  ;
	buf[0]=(0x01<<2)||(SerialReg<<6)                              ;                                 
	buf[1]=SerialReg                                              ;                                   
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
}	


/*	
   @Brief		Read contents of wiper register
   @Description		Read value of potentiometer
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	uint16_t
 */
uint16_t AD5175_readRDAC(I2C_HandleTypeDef i2c)
{	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x02<<2                                                ;
	buf[1]=0x00                                                   ;
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
	HAL_Delay(1)                                                  ;
	HAL_I2C_Master_Receive(&i2c,AD5175_DeviceID<<2,buf,2,100)            ;
	return ((buf[0]<<8)|(buf[1]<<1))                              ;
}	


/*	
   @Brief		Store wiper setting: store RDAC setting to 50-TP
   @Description		If you want to store resistor value of potentiometer, use this
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	None
 */
void AD5175_storeWiperSet(I2C_HandleTypeDef i2c)        	
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x03<<2                                                ;
	buf[1]=0x00                                                   ;	
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
}	


/*	
   @Brief		Software reset
   @Description		Refresh RDAC with the last 50-TP memory stored value.
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	None
 */
void AD5175_softwareReset(I2C_HandleTypeDef i2c)        	
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x04<<2                                                ;
	buf[1]=0x00                                                   ;	
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
}	


/*	
   @Brief		Read contents of 50-TP from the SDO output in the next frame
   @Description		
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   			uint8_t 		-> Wiper Location of 50 TP, set from da header file
   @Return value	uint16_t
 */
uint16_t AD5175_nextFrameRead(I2C_HandleTypeDef i2c,uint8_t WiperLocation)    	
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x05<<2                                                ;
	buf[1]=WiperLocation                                          ;	
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
	HAL_Delay(1)                                                  ;
	HAL_I2C_Master_Receive(&i2c,AD5175_DeviceID<<2,buf,2,100)            ;
	return ((buf[0]<<8)|(buf[1]<<1))                              ;
}	


/*	
   @Brief		Read AD5175_DeviceIDess of the last 50-TP programmed memory location
   @Description		
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	uint16_t
 */
uint16_t AD5175_readMemory(I2C_HandleTypeDef i2c)       
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x06<<2                                                ;
	buf[1]=0x00                                                   ;	
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;	
	HAL_Delay(1)                                                  ;
	HAL_I2C_Master_Receive(&i2c,AD5175_DeviceID<<2,buf,2,100)	      ;
	return ((buf[0]<<8)|(buf[1]<<1))                              ;
}	


/*	
   @Brief			Write contents of the serial register data to the control register.
   @Description		Control register area based on tabele 10
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	None
 */
void AD5175_writeControlReg(I2C_HandleTypeDef i2c)      	
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x07<<2                                                ;
	buf[1]=0x00                                                   ;	//Default Control Register.When programming TP, change this byte
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
}


/*	
   @Brief		Read contents of the control register
   @Description		Control register area based on tabele 10
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	uint16_t
 */
uint16_t AD5175_readControlReg(I2C_HandleTypeDef i2c)
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x08<<2                                                ;
	buf[1]=0x00                                                   ;	
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)           ;
	HAL_Delay(1)                                                  ;
	HAL_I2C_Master_Receive(&i2c,AD5175_DeviceID<<2,buf,2,100)            ;
	return ((buf[0]<<8)|(buf[1]<<1))                              ;
}


/*	
   @Brief		Software shutdown
   @Description		Disable AD5175
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   			uint8_t			-> shtdwn = 0 normal mode, shtdwn = 1 shutdown mode
   @Return value	None
 */
void AD5175_softwareShutdown(I2C_HandleTypeDef i2c,uint8_t shtdwn)     	
{	
	static uint8_t buf[2]                                         ;
	HAL_Delay(1)                                                  ;
	buf[0]=0x09<<2                                                ;
	buf[1]=shtdwn                                                 ;	
	HAL_I2C_Master_Transmit(&i2c,AD5175_DeviceID<<2,buf,2,100)	      ;
}



