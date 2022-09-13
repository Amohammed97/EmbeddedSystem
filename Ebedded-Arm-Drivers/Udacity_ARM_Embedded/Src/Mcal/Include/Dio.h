/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  DIO
 *
 *  Description:  header file for DIO Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define Gpio_Mask_255 0x3FC
typedef enum
{

	Dio_Channel_A0,
	Dio_Channel_A1,
	Dio_Channel_A2,
	Dio_Channel_A3,
	Dio_Channel_A4,
	Dio_Channel_A5,
	Dio_Channel_A6,
	Dio_Channel_A7,

	Dio_Channel_B0,
	Dio_Channel_B1,
	Dio_Channel_B2,
	Dio_Channel_B3,
	Dio_Channel_B4,
	Dio_Channel_B5,
	Dio_Channel_B6,
	Dio_Channel_B7,

	Dio_Channel_C0,
	Dio_Channel_C1,
	Dio_Channel_C2,
	Dio_Channel_C3,
	Dio_Channel_C4,
	Dio_Channel_C5,
	Dio_Channel_C6,
	Dio_Channel_C7,

	Dio_Channel_D0,
	Dio_Channel_D1,
	Dio_Channel_D2,
	Dio_Channel_D3,
	Dio_Channel_D4,
	Dio_Channel_D5,
	Dio_Channel_D6,
	Dio_Channel_D7,

	Dio_Channel_E0,
	Dio_Channel_E1,
	Dio_Channel_E2,
	Dio_Channel_E3,
	Dio_Channel_E4,
	Dio_Channel_E5,
	Dio_Channel_E6_RESERVED,
	Dio_Channel_E7_RESERVED,

	Dio_Channel_F0,
	Dio_Channel_F1,
	Dio_Channel_F2,
	Dio_Channel_F3,
	Dio_Channel_F4,
	Dio_Channel_F5_RESERVED,
	Dio_Channel_F6_RESERVED,
	Dio_Channel_F7_RESERVED,

} Dio_ChannelType;

typedef enum
{

	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
} Dio_PortType;

typedef STD_levelType Dio_LevelType;

typedef uint8 Dio_PortLevelType;

typedef struct
{
	uint8 mask;
	uint8 offset;
	Dio_PortType port;
} Dio_ChannelGroupType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Service name		 : Dio_ReadChannel
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Returns the value of the specified DIO channel.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId -> ID of DIO channel                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType -> STD_HIGH The physical level of the corresponding Pin is STD_HIGH 
																	 -> STD_LOW  The physical level of the corresponding Pin is STD_LOW                                  
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/******************************************************************************
* \Service name		 : Dio_WriteChannel
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Service to set a level of a channel.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId     -> ID of DIO channel
										 Level				 ->	Value to be written                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/******************************************************************************
* \Service name		 : Dio_ReadPort
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Returns the level of all channels of that port.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId     	 ->	ID of DIO Port
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType 	->	Level of all channels of that port                                
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/******************************************************************************
* \Service name		 : Dio_WritePort
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Service to set a value of the port.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId	->	ID of DIO Port
										 Level	->	Value to be written
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/******************************************************************************
* \Service name		 : Dio_FlipChannel
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )        
* \Description     : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel 
										 and return the level of the channel after flip.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId	->	ID of DIO channel
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType	->	STD_HIGH: The physical level of the corresponding Pin is STD_HIGH.
										STD_LOW: The physical level of the corresponding Pin is STD_LOW.                                
*******************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/******************************************************************************
* \Service name		 : Dio_WriteChannelGroup
* \Syntax          : void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )        
* \Description     : Service to set a subset of the adjoining bits of a port to a specified level.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelGroupIdPtr	->	Pointer to ChannelGroup
										 Level	->	Value to be written
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
// void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);

/******************************************************************************
* \Service name		 : Dio_ReadChannelGroup
* \Syntax          : Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )        
* \Description     : This Service reads a subset of the adjoining bits of a port.                                                                  
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelGroupIdPtr	->	Pointer to ChannelGroup
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType	->	Level of a subset of the adjoining bits of a port                               
*******************************************************************************/
// Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);

#endif /* Dio_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
