/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

// Group     Feild Data is between GroupX 
// SubGroup Feild Data is between  SubGroupX
// WHERE X From 0-7
// Interrupt_CfgType array Data is {InterrupName , GroupX , SubGroupX}

const Interrupt_CfgType Interrupt_Groups[NUM_OF_ACTIVATED_GROUPS]   =
{	
    { Interrupt_Timer_0A_16_32 , Group0	, SubGroup0 }
};
	

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
