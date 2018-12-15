/*
  @
  @   Date               :        10.08.2018 / Friday
  @
  @   Contact            :        Editing by Muhammet Rasit KIYAK                     @https://www.linkedin.com/in/mrstkyk/
  @                               mrstkyk@gmail.com
  @
  @   Description        :        This Library for AD5175(Digital Potentiometer)
  @                               Dependency library is HAL for STM32 series (__STM32L4xx_HAL_I2C_H)
  @
*/

#ifndef      _AD5175_H_	
#define      _AD5175_H_	

	/*
	Check the model of your MCU model
	*/
	#ifndef     __STM32L4xx_HAL_I2C_H
	#define     __STM32L4xx_HAL_I2C_H
	#endif	

	/*
	Please check these pins connections are A1 and A0
	If your device ID's wrong, MCU does not find your potentiometer
	*/
	#define     AD5175_DeviceID0 0x2F 			        //A1->1,A0->1 GND
	#define     AD5175_DeviceID1 0x2C 			        //A1->0,A0->0 VCC
	#define     AD5175_DeviceID2 0x2E 			        //A1->1,A0->0 Not Connect	

	/*
	50 Time Programmable Wiper Location Address
	*/
	#define	wiperLocation_1		0x01            //1	 programmed wiper location
	#define	wiperLocation_2		0x02            //2	 programmed wiper location
	#define	wiperLocation_3		0x03            //3	 programmed wiper location
	#define	wiperLocation_4		0x04            //4	 programmed wiper location
	#define	wiperLocation_5		0x05            //5	 programmed wiper location
	#define	wiperLocation_6		0x06            //6	 programmed wiper location
	#define	wiperLocation_7		0x07            //7	 programmed wiper location
	#define	wiperLocation_8		0x08            //8	 programmed wiper location
	#define	wiperLocation_9		0x09            //9	 programmed wiper location
	#define	wiperLocation_10	0x0A            //10 programmed wiper location
	#define	wiperLocation_11	0x0B            //11 programmed wiper location
	#define	wiperLocation_12	0x0C            //12 programmed wiper location
	#define	wiperLocation_13	0x0D            //13 programmed wiper location
	#define	wiperLocation_14	0x0E            //14 programmed wiper location
	#define	wiperLocation_15	0x0F            //15 programmed wiper location
	#define	wiperLocation_16	0x10            //16 programmed wiper location
	#define	wiperLocation_17	0x11            //17 programmed wiper location
	#define	wiperLocation_18	0x12            //18 programmed wiper location
	#define	wiperLocation_19	0x13            //19 programmed wiper location
	#define	wiperLocation_20	0x14            //20 programmed wiper location
	#define	wiperLocation_21	0x15            //21 programmed wiper location
	#define	wiperLocation_22	0x16            //22 programmed wiper location
	#define	wiperLocation_23	0x17            //23 programmed wiper location
	#define	wiperLocation_24	0x18            //24 programmed wiper location
	#define	wiperLocation_25	0x19            //25 programmed wiper location
	#define	wiperLocation_26	0x1A            //26 programmed wiper location
	#define	wiperLocation_27	0x1B            //27 programmed wiper location
	#define	wiperLocation_28	0x1C            //28 programmed wiper location
	#define	wiperLocation_29	0x1D            //29 programmed wiper location
	#define	wiperLocation_30	0x1E            //30 programmed wiper location
	#define	wiperLocation_31	0x1F            //31 programmed wiper location
	#define	wiperLocation_32	0x20            //32 programmed wiper location
	#define	wiperLocation_33	0x21            //33 programmed wiper location
	#define	wiperLocation_34	0x22            //34 programmed wiper location
	#define	wiperLocation_35	0x23            //35 programmed wiper location
	#define	wiperLocation_36	0x24            //36 programmed wiper location
	#define	wiperLocation_37	0x25            //37 programmed wiper location
	#define	wiperLocation_38	0x26            //38 programmed wiper location
	#define	wiperLocation_39	0x27            //39 programmed wiper location
	#define	wiperLocation_40	0x28            //40 programmed wiper location
	#define	wiperLocation_41	0x29            //41 programmed wiper location
	#define	wiperLocation_42	0x2A            //42 programmed wiper location
	#define	wiperLocation_43	0x2B            //43 programmed wiper location
	#define	wiperLocation_44	0x2C            //44 programmed wiper location
	#define	wiperLocation_45	0x2D            //45 programmed wiper location
	#define	wiperLocation_46	0x2E            //46 programmed wiper location
	#define	wiperLocation_47	0x2F            //47 programmed wiper location
	#define	wiperLocation_48	0x30            //48 programmed wiper location
	#define	wiperLocation_49	0x31            //49 programmed wiper location
	#define	wiperLocation_50	0x32            //50 programmed wiper location




/*	
   @Brief			Write contents of serial register data to RDAC
   @Description		There is 10 bit resolution this potentiometer.
   					Calculation is [(10000/1024)*SerialReg]= Resistor Value
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   					SerialReg			-> Step of potentiometer.10 bit resolution
   @Return value	None
 */
void AD5175_writeRDAC(I2C_HandleTypeDef i2c,uint16_t SerialReg)            ;


/*	
   @Brief			Read contents of wiper register
   @Description		Read value of potentiometer
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	uint16_t
 */
uint16_t AD5175_readRDAC(I2C_HandleTypeDef i2c)                            ;


/*	
   @Brief			Store wiper setting: store RDAC setting to 50-TP
   @Description		If you want to store resistor value of potentiometer, use this
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	None
 */
void AD5175_storeWiperSet(I2C_HandleTypeDef i2c)        	               ;


/*	
   @Brief			Software reset
   @Description		Refresh RDAC with the last 50-TP memory stored value.
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	None
 */
void AD5175_softwareReset(I2C_HandleTypeDef i2c)        	               ;


/*	
   @Brief			Read contents of 50-TP from the SDO output in the next frame
   @Description		
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   					uint8_t 			-> Wiper Location of 50 TP, set from da header file
   @Return value	uint16_t
 */
uint16_t AD5175_nextFrameRead(I2C_HandleTypeDef i2c,uint8_t WiperLocation) ;


/*	
   @Brief			Read DeviceIDess of the last 50-TP programmed memory location
   @Description		
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	uint16_t
 */
uint16_t AD5175_readMemory(I2C_HandleTypeDef i2c)                          ;


/*	
   @Brief			Write contents of the serial register data to the control register.
   @Description		Control register area based on tabele 10
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	None
 */
void AD5175_writeControlReg(I2C_HandleTypeDef i2c)      	               ;


/*	
   @Brief			Read contents of the control register
   @Description		Control register area based on tabele 10
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   @Return value	uint16_t
 */
uint16_t AD5175_readControlReg(I2C_HandleTypeDef i2c)                      ;


/*	
   @Brief			Software shutdown
   @Description		Disable AD5175
   @Parameter		I2C_HandleTypeDef	-> HAL_I2C Handle
   					uint8_t				-> shtdwn = 0 normal mode, shtdwn = 1 shutdown mode
   @Return value	None
 */
void AD5175_softwareShutdown(I2C_HandleTypeDef i2c,uint8_t shtdwn)     	   ;



#endif

