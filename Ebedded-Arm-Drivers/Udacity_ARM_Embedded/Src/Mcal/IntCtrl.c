/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	uint32 	
	priRegOffset ,	
	priBitOffset , 	
	enRegOffset	 ,	
	enBitOffset	 ;
	
	uint8 	
	interrupt_Number	,	
	group_Value 		, 	
	subGroup_Value 		, 	
	grouping_Field		;

	APINT.B.VECTKEY		=	APINT_VECTKEY; 				// Field Guard
	APINT.B.ENDIANESS	=	STD_LOW;					//Little-Endian Mode
	APINT.B.PRIGROUP 	= 	GROUPING_SYSTEM;      	//The Split Of Group Priority From Subpriority

	for (uint8 i = 0; i < NUM_OF_ACTIVATED_GROUPS; i++)
	{
		/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
		interrupt_Number	 = Interrupt_Groups[i].Interrupt_Number;	
		group_Value 		 = Interrupt_Groups[i].Group_Priority;
		subGroup_Value 		 = Interrupt_Groups[i].SubGroup_Priority;
		
		/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		enRegOffset = (interrupt_Number/32)*4;	//Which ENX Register
		enBitOffset = interrupt_Number%32; 		//Which bit inside chosen ENX Register
    	AddressAccess(NVIC_ENX_BASE_ADDRESS + enRegOffset  ) |= (1 << enBitOffset);	
		
		/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/ 
		#if   ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXX)
	
		grouping_Field=Group_Temp ;
	
		#elif ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXY)
	
		grouping_Field=(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));

		#elif ( GROUPING_SYSTEM == GROUPING_SYSTEM_XYY)
	
		grouping_Field=(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));	

		#elif ( GROUPING_SYSTEM == GROUPING_SYSTEM_YYY)
	
		grouping_Field= subGroup_Value ;

		#endif
		// NVIC PRI REG 
		priRegOffset = (interrupt_Number/4)*4;
		priBitOffset = (8 * (interrupt_Number%4)) + 5; //Which 3-bits inside chosen PRIX Register
		AddressAccess(NVIC_PRIX_BASE_ADDRESS + priRegOffset  ) |= ((uint32)(grouping_Field << priBitOffset));


	}
	


	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
