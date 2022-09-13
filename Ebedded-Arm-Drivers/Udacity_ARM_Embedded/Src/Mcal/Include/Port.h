/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  header file for Port Module    
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define UNLOCK_KEY 0x4C4F434B

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
} Port_PinDirectionType;

typedef Dio_ChannelType Port_PinType;

typedef enum
{
	DEFAULT,
	PULLUP,
	PULLDOWN,
	OPENDRAIN
} Port_PinInternalAttachType;

typedef uint8 Port_PinModeType;

#define DIO 0

#define A0_U0Rx 1
#define A1_U0Tx 1

#define A2_SSI0Clk 2
#define A3_SSI0Fss 2
#define A4_SSI0Rx 2
#define A5_SSI0Tx 2

#define A6_I2C1SCL 3
#define A7_I2C1SDA 3

#define A6_M1PWM2 5
#define A7_M1PWM3 5

#define A0_CAN1Rx 8
#define A1_CAN1Tx 8

#define B0_U1Rx 1
#define B1_U1Tx 1

#define B4_SSI2Clk 2
#define B5_SSI2Fss 2
#define B6_SSI2Rx 2
#define B7_SSI2Tx 2

#define B2_I2C0SCL 3
#define B3_I2C0SDA 3

#define B4_M0PWM2 4
#define B5_M0PWM3 4
#define B6_M0PWM0 4
#define B7_M0PWM1 4

#define B0_T2CCP0 7
#define B1_T2CCP1 7
#define B2_T3CCP0 7
#define B3_T3CCP1 7
#define B4_T1CCP0 7
#define B5_T1CCP1 7
#define B6_T0CCP0 7
#define B7_T0CCP1 7

#define B4_CAN0Rx 8
#define B5_CAN0Tx 8

#define C0_TCK_SWCLK 1
#define C1_TMS_SWDIO 1
#define C2_TDI 1
#define C3_TDO_SWO 1
#define C4_U4Rx 1
#define C5_U4Tx 1
#define C6_U3Rx 1
#define C7_U3Tx 1

#define C4_M0PWM2 4
#define C5_M0PWM3 4
#define C6_M0PWM0 4
#define C7_M0PWM1 4

#define C4_IDX1 6
#define C5_PhA1 6
#define C6_PhB1 6

#define C0_T4CCP0 7
#define C1_T4CCP1 7
#define C2_T5CCP0 7
#define C3_T5CCP1 7
#define C4_WT0CCP0 7
#define C5_WT0CCP1 7
#define C6_WT1CCP0 7
#define C7_WT1CCP1 7

#define C4_U1RTS 8
#define C5_U1CTS 8
#define C6_USB0EPEN 8
#define C7_USB0PFLT 8

#define D0_SSI3Clk 1
#define D1_SSI3Fss 1
#define D2_SSI3Rx 1
#define D3_SSI3Tx 1
#define D4_U6Rx 1
#define D5_U6Tx 1
#define D6_U2Rx 1
#define D7_U2Tx 1

#define D0_SSI1Clk 2
#define D1_SSI1Fss 2
#define D2_SSI1Rx 2
#define D3_SSI1Tx 2

#define D0_I2C3SCL 3
#define D1_I2C3SDA 3

#define D0_M0PWM6 4
#define D1_M0PWM7 4
#define D2_M0FAULT0 4

#define D0_M1PWM0 5
#define D1_M1PWM1 5

#define D3_IDX0 6
#define D6_PhA0 6
#define D7_PhB0 6

#define D0_WT2CCP0 7
#define D1_WT2CCP1 7
#define D2_WT3CCP0 7
#define D3_WT3CCP1 7
#define D4_WT4CCP0 7
#define D5_WT4CCP1 7
#define D6_WT5CCP0 7
#define D7_WT5CCP1 7

#define D2_USB0EPEN 8
#define D3_USB0PFLT 8
#define D7_NMI 8

#define E0_U7Rx 1
#define E1_U7Tx 1
#define E4_U5Rx 1
#define E5_U5Tx 1

#define E4_I2C2SCL 3
#define E5_I2C2SDA 3

#define E4_M0PWM4 4
#define E5_M0PWM5 4

#define E4_M1PWM2 5
#define E5_M1PWM3 5

#define E4_CAN0Rx 8
#define E5_CAN0Tx 8

#define F0_U1RTS 1
#define F1_U1CTS 1

#define F0_SSI1Rx 2
#define F1_SSI1Tx 2
#define F2_SSI1Clk 2
#define F3_SSI1Fss 2

#define F0_CAN0Rx 3
#define F3_CAN0Tx 3

#define F2_M0FAULT0 4

#define F0_M1PWM4 5
#define F1_M1PWM5 5
#define F2_M1PWM6 5
#define F3_M1PWM7 5
#define F4_M1FAULT0 5

#define F0_PhA0 6
#define F1_PhB0 6
#define F4_IDX0 6

#define F0_T0CCP0 7
#define F1_T0CCP1 7
#define F2_T1CCP0 7
#define F3_T1CCP1 7
#define F4_T2CCP0 7

#define F0_NMI 8
#define F4_USB0EPEN 8

#define F0_C0o 9
#define F1_C1o 9

#define F1_TRD1 14
#define F2_TRD0 14
#define F3_TRCLK 14

typedef enum
{
	CURRENT_NA,
	CURRENT_2M,
	CURRENT_4M,
	CURRENT_8M
} Port_PinOutputCurrentType;

typedef struct
{
	Port_PinType Pin;
	Port_PinDirectionType Dir;
	Port_PinModeType Mode;
	Port_PinInternalAttachType Attach;
	Port_PinOutputCurrentType OutputCurr;

} Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Service name		: Port_Init
* \Syntax          	: void Port_Init( const Port_ConfigType* ConfigPtr )        
* \Description     	: Initializes the Port Driver module.                                                                  
* \Sync\Async      	: Synchronous                                               
* \Reentrancy      	: Non Reentrant                                             
* \Parameters (in) 	: ConfigPtr	->	Pointer to configuration set.
* \Parameters (out)	: None                                                      
* \Return value:   	: None                               
*******************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr);

#endif /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
