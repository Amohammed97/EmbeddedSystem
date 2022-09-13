/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
 *        \brief  Timer Driver
 *
 *      \details  The Driver Configure All Timer from 0 - 5 and Enable Interrupt for each timer 
 * 				  Also using Callback function to excute User Function
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
// extern volatile uint32 GlobalSystemClock;

#define End_16_32_Timers GPT_16_32_BIT_TIMER5

static const Gpt_ConfigType* globalGptConfig;

GptNotification	locGptNotification[MAX_NUMBER_OF_GPIO_GPT];

static const uint32 Gpt_BaseAddress[MAX_NUMBER_OF_GPIO_GPT] =   {   _16_32_BIT_TIMER_0_BASE_ADDRESS,			
															        _16_32_BIT_TIMER_1_BASE_ADDRESS,		
															        _16_32_BIT_TIMER_2_BASE_ADDRESS,			
															        _16_32_BIT_TIMER_3_BASE_ADDRESS,			
															        _16_32_BIT_TIMER_4_BASE_ADDRESS,			
	                                                                _16_32_BIT_TIMER_5_BASE_ADDRESS,			
															        _32_64_BIT_WIDE_TIMER_0_BASE_ADDRESS,
															        _32_64_BIT_WIDE_TIMER_1_BASE_ADDRESS,
															        _32_64_BIT_WIDE_TIMER_2_BASE_ADDRESS,
															        _32_64_BIT_WIDE_TIMER_3_BASE_ADDRESS,
															        _32_64_BIT_WIDE_TIMER_4_BASE_ADDRESS,
																	_32_64_BIT_WIDE_TIMER_5_BASE_ADDRESS
																};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr)
{
	Gpt_ChannelType 				Channel_Name ;					
	Gpt_ChannelTickFrequency 		TickFrequency; 
	GptChannelTickValueMax  		TickValueMax;
	ChannelMode						Mode;

	globalGptConfig = ConfigPtr;

	for(uint8 Counter =0 ; Counter < GPT_ACTIVATED_CHANNELS_SIZE;	Counter ++)
	{
		Channel_Name=ConfigPtr[Counter].channel;			
		// TickFrequency=ConfigPtr[Counter].channelTickFreq;	
		TickValueMax=ConfigPtr[Counter].channelTickMaxValue;	
		Mode=ConfigPtr[Counter].channelMode;
		locGptNotification[Channel_Name]= ConfigPtr[Counter].gptNotification;


		if(Channel_Name <= End_16_32_Timers)
		{
			/* 16_32_Timers*/
			//Initialization and Configuration
			AddressAccess(RCGCTIMER_BASE_ADDRESS + RCGCTIMER_OFFSET) |= ((uint32)((1<<Channel_Name))); // Enable Timer Module			
			//1
			AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMCTL_OFFSET  ) &= ((uint32)(~(1<<0))); 	// Disable Timer A

			if(TickValueMax <= 0XFFFF)
			{
				//2
				AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMCFG_OFFSET  ) = 0x4;        // To Use 16-Bit
			}
			else
			{
				//2
				AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMCFG_OFFSET  ) = 0x0;        // To Use 32-Bit
			}

			if (Mode == GPT_CH_MODE_CONTINUOUS)
			{
				//3
				AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMTAMR_OFFSET  ) |= 0x2; //Set Periodic mode

			}
			else if(Mode == GPT_CH_MODE_ONESHOT)
			{
				//3
				/* TO_DO GPT_CH_MODE_ONESHOT Configuration*/
			    AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMTAMR_OFFSET  ) |= 0x1; //Set One_Shot mode
				
			}

				//3
				AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMTAMR_OFFSET  ) |= ~(1<<4) ; // The Timer Counts down. 


		}
		else
		{
			/* TO_DO 32_64_Timers Configuration*/
				
		}	
		Gpt_DisableNotification(Channel_Name);	
	}
}
	/******************************************************************************
* \Syntax          : void Gpt_DisableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
	AddressAccess(Gpt_BaseAddress[Channel] + GPTMIMR_OFFSET  ) &= ((uint32)(~(1<<0)));
}

	/******************************************************************************
* \Syntax          : void Gpt_EnableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel )
{
	AddressAccess(Gpt_BaseAddress[Channel]  + GPTMIMR_OFFSET) |= ((uint32)((1<<0))); // Enable  Timer A Time-Out Interrupt Mask			
}

/******************************************************************************
* \Syntax          : Gpt_GetTimeElapsed( Gpt_ChannelType Channel )        
* \Description     : Returns the time already elapsed.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): Gpt_ValueType                                                      
* \Return value:   : Gpt_ValueType  uint32                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel )
{

	Gpt_ValueType value;
	value 		 =	 AddressAccess(Gpt_BaseAddress[Channel] + GPTMTAILR_OFFSET  );
	return value;
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )       
* \Description     : Returns the time remaining until the target time is reached.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  uint32                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{

	Gpt_ValueType value, currentValue, remainingValue;

	currentValue = 	 AddressAccess(Gpt_BaseAddress[Channel] + GPTMTAV_OFFSET  );
	value 		 =	 AddressAccess(Gpt_BaseAddress[Channel] + GPTMTAILR_OFFSET  );

	return remainingValue;

}

/******************************************************************************
* \Syntax          : void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );        
* \Description     : Starts a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant(but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel. 
*										 Value		 Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
	Gpt_ChannelTickFrequency ChannelTickFreq	 = 0;
	GptChannelTickValueMax   ChannelTickValueMax = 0;
	Gpt_ChannelType Channel_Name =0;
	uint32 Prescale;

		


	/* 16_32 Timer */
	if(Channel <= End_16_32_Timers)
	{
				// To Get The Channel Tick Freq and Max Value  
		for(uint8 Counter=0; Counter < MAX_NUMBER_OF_GPIO_GPT ; Counter++)
		{
			if (globalGptConfig[Counter].channel == Channel)
			{
				ChannelTickFreq 	= globalGptConfig[Counter].channelTickFreq;			
				ChannelTickValueMax = globalGptConfig[Counter].channelTickMaxValue;
				Channel_Name		=globalGptConfig[Counter].channel;
				break;
			}
		}

		Prescale = (GlobalSystemClock / ChannelTickFreq);
		if (Prescale > 255)	{
			#warning the input not suitable
			Prescale = 255; 
		}

		AddressAccess(Gpt_BaseAddress[Channel_Name]  + GPTMTAPR_OFFSET	)  = ((uint32)(Prescale)); /* TimerA prescaler value */			
		AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMTAILR_OFFSET  )  = Value;
		AddressAccess( _16_32_BIT_TIMER_0_BASE_ADDRESS + GPTMICR_OFFSET ) |= 0x1;
		AddressAccess(Gpt_BaseAddress[Channel_Name] + GPTMCTL_OFFSET  	) |= ((uint32)((1<<0))); 	// Enable Timer A
	}
	/* 32_64 Timer */
	else
	{
		/* TO_DO 32_64_Timers Configuration*/
	}
	
}
/*
/******************************************************************************
* \Syntax          : void Gpt_StopTimer( Gpt_ChannelType Channel )       
* \Description     : Stops a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                           
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
	(*((volatile uint32*)(Gpt_BaseAddress[Channel] + GPTMCTL_OFFSET  ))) &= ((uint32)(~(1<<0)));

}


void TIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_16_32_BIT_TIMER0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_16_32_BIT_TIMER0];
		gptNotificationFn_TIMER0A();
		AddressAccess( _16_32_BIT_TIMER_0_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;
	}
}

void TIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER1A;
	if (locGptNotification[GPT_16_32_BIT_TIMER1] != NULL)
	{
		gptNotificationFn_TIMER1A = locGptNotification[GPT_16_32_BIT_TIMER1];
		gptNotificationFn_TIMER1A();
		AddressAccess( _16_32_BIT_TIMER_1_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;

	}
}

void TIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER2A;
	if (locGptNotification[GPT_16_32_BIT_TIMER2] != NULL)
	{
		gptNotificationFn_TIMER2A = locGptNotification[GPT_16_32_BIT_TIMER2];
		gptNotificationFn_TIMER2A();
		AddressAccess( _16_32_BIT_TIMER_2_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;

	}
}

void TIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER3A;
	if (locGptNotification[GPT_16_32_BIT_TIMER3] != NULL)
	{
		gptNotificationFn_TIMER3A = locGptNotification[GPT_16_32_BIT_TIMER3];
		gptNotificationFn_TIMER3A();
		AddressAccess( _16_32_BIT_TIMER_3_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;

	}
}

void TIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER4A;
	if (locGptNotification[GPT_16_32_BIT_TIMER4] != NULL)
	{
		gptNotificationFn_TIMER4A = locGptNotification[GPT_16_32_BIT_TIMER4];
		gptNotificationFn_TIMER4A();
		AddressAccess( _16_32_BIT_TIMER_4_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;
	} 
}

void TIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER5A;
	if (locGptNotification[GPT_16_32_BIT_TIMER5] != NULL)
	{
		gptNotificationFn_TIMER5A = locGptNotification[GPT_16_32_BIT_TIMER5];
		gptNotificationFn_TIMER5A();
		AddressAccess( _16_32_BIT_TIMER_5_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;

	}
}

void WTIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER0A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER0] != NULL)
	{
		gptNotificationFn_WTIMER0A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER0];
		gptNotificationFn_WTIMER0A();
		AddressAccess( _32_64_BIT_WIDE_TIMER_0_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;
	}
}

void WTIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER1A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER1] != NULL)
	{
		gptNotificationFn_WTIMER1A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER1];
		gptNotificationFn_WTIMER1A();
		AddressAccess( _32_64_BIT_WIDE_TIMER_1_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;
	}
}

void WTIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER2A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER2] != NULL)
	{
		gptNotificationFn_WTIMER2A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER2];
		gptNotificationFn_WTIMER2A();
		AddressAccess( _32_64_BIT_WIDE_TIMER_2_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;
	}
}

void WTIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER3A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER3] != NULL)
	{
		gptNotificationFn_WTIMER3A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER3];
		gptNotificationFn_WTIMER3A();
		AddressAccess( _32_64_BIT_WIDE_TIMER_3_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;
	}
}

void WTIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER4A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER4] != NULL)
	{
		gptNotificationFn_WTIMER4A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER4];
		gptNotificationFn_WTIMER4A();
		AddressAccess( _32_64_BIT_WIDE_TIMER_4_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;

	}
}

void WTIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER5A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER5] != NULL)
	{
		gptNotificationFn_WTIMER5A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER5];
		gptNotificationFn_WTIMER5A();
		AddressAccess( _32_64_BIT_WIDE_TIMER_5_BASE_ADDRESS + GPTMICR_OFFSET )|= 0x1;

	}
}

/**********************************************************************************************************************
 *  END OF FILE: Timer.c
 *********************************************************************************************************************/
