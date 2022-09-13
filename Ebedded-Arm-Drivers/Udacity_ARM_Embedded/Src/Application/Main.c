#include "Main.h"

extern const Port_ConfigType Port_Config[];
extern const Gpt_ConfigType Gpt_Config[];
#define Time_On 	10
#define Time_Off 	5


int main ( void )
{
	Port_Init(Port_Config);
	IntCrtl_Init();
	Gpt_Init(Gpt_Config);
	Gpt_StartTimer(GPT_16_32_BIT_TIMER0,63999);
	Gpt_EnableNotification(GPT_16_32_BIT_TIMER0);

	while (STD_HIGH) 
	{  
	}
}

