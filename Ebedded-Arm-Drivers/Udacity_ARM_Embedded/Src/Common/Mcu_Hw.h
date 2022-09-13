/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define AddressAccess(Address) (*((volatile uint32 *)(Address)))

#define GPIODATA_OFFSET                         0x000
#define GPIODIR_OFFSET                          0x400
#define GPIOIS_OFFSET                           0x404
#define GPIOIBE_OFFSET                          0x408
#define GPIOIEV_OFFSET                          0x40C
#define GPIOIM_OFFSET                           0x410
#define GPIORIS_OFFSET                          0x414
#define GPIOMIS_OFFSET                          0x418
#define GPIOICR_OFFSET                          0x41C
#define GPIOAFSEL_OFFSET                        0x420
#define GPIODR2R_OFFSET                         0x500
#define GPIODR4R_OFFSET                         0x504
#define GPIODR8R_OFFSET                         0x508
#define GPIOODR_OFFSET                          0x50C
#define GPIOPUR_OFFSET                          0x510
#define GPIOPDR_OFFSET                          0x514
#define GPIOSLR_OFFSET                          0x518
#define GPIODEN_OFFSET                          0x51C
#define GPIOLOCK_OFFSET                         0x520
#define GPIOCR_OFFSET                           0x524
#define GPIOAMSEL_OFFSET                        0x528
#define GPIOPCTL_OFFSET                         0x52C
#define GPIOADCCTL_OFFSET                       0x530
#define GPIODMACTL_OFFSET                       0x534
#define RCGCGPIO_OFFSET                         0x608

#define GPIO_PORTA_APB_BASE_ADDRESS             0x40004000
#define GPIO_PORTA_AHB_BASE_ADDRESS             0x40058000
#define GPIO_PORTB_APB_BASE_ADDRESS             0x40005000
#define GPIO_PORTB_AHB_BASE_ADDRESS             0x40059000
#define GPIO_PORTC_APB_BASE_ADDRESS             0x40006000
#define GPIO_PORTC_AHB_BASE_ADDRESS             0x4005A000
#define GPIO_PORTD_APB_BASE_ADDRESS             0x40007000
#define GPIO_PORTD_AHB_BASE_ADDRESS             0x4005B000
#define GPIO_PORTE_APB_BASE_ADDRESS             0x40024000
#define GPIO_PORTE_AHB_BASE_ADDRESS             0x4005C000
#define GPIO_PORTF_APB_BASE_ADDRESS             0x40025000
#define GPIO_PORTF_AHB_BASE_ADDRESS             0x4005D000
#define RCGCGPIO_BASE_ADDRESS                   0x400FE000


#define _16_32_BIT_TIMER_0_BASE_ADDRESS         0x40030000
#define _16_32_BIT_TIMER_1_BASE_ADDRESS         0x40031000
#define _16_32_BIT_TIMER_2_BASE_ADDRESS         0x40032000
#define _16_32_BIT_TIMER_3_BASE_ADDRESS         0x40033000
#define _16_32_BIT_TIMER_4_BASE_ADDRESS         0x40034000
#define _16_32_BIT_TIMER_5_BASE_ADDRESS         0x40035000
#define _32_64_BIT_WIDE_TIMER_0_BASE_ADDRESS    0x40036000
#define _32_64_BIT_WIDE_TIMER_1_BASE_ADDRESS    0x40037000
#define _32_64_BIT_WIDE_TIMER_2_BASE_ADDRESS    0x4004C000
#define _32_64_BIT_WIDE_TIMER_3_BASE_ADDRESS    0x4004D000
#define _32_64_BIT_WIDE_TIMER_4_BASE_ADDRESS    0x4004E000
#define _32_64_BIT_WIDE_TIMER_5_BASE_ADDRESS    0x4004F000
#define RCGCTIMER_BASE_ADDRESS                  0x400FE000

#define GPTMCFG_OFFSET      0x000
#define GPTMTAMR_OFFSET     0x004
#define GPTMTBMR_OFFSET     0x008
#define GPTMCTL_OFFSET      0x00C
#define GPTMSYNC_OFFSET     0x010
#define GPTMIMR_OFFSET      0x018
#define GPTMRIS_OFFSET      0x01C
#define GPTMMIS_OFFSET      0x020
#define GPTMICR_OFFSET      0x024
#define GPTMTAILR_OFFSET    0x028
#define GPTMTBILR_OFFSET    0x02C
#define GPTMTAMATCHR_OFFSET 0x030
#define GPTMTBMATCHR_OFFSET 0x034
#define GPTMTAPR_OFFSET     0x038
#define GPTMTBPR_OFFSET     0x03C
#define GPTMTAPMR_OFFSET    0x040
#define GPTMTBPMR_OFFSET    0x044
#define GPTMTAR_OFFSET      0x048
#define GPTMTBR_OFFSET      0x04C
#define GPTMTAV_OFFSET      0x050
#define GPTMTBV_OFFSET      0x054
#define GPTMRTCPD_OFFSET    0x058
#define GPTMTAPS_OFFSET     0x05C
#define GPTMTBPS_OFFSET     0x060
#define GPTMTAPV_OFFSET     0x064
#define GPTMTBPV_OFFSET     0x068
#define GPTMPP_OFFSET       0xFC0
#define RCGCTIMER_OFFSET    0x604

typedef struct 
{
    uint32 R0 : 1;
    uint32 R1 : 1;
    uint32 R2 : 1;
    uint32 R3 : 1;
    uint32 R4 : 1;
    uint32 R5 : 1;
    uint32    : 26;
}RCGCTIMER_BF;

typedef union
{
    uint32       R;
    RCGCTIMER_BF B;
}RCGCTIMER_Tag;


typedef struct 
{
    uint32 VECACT       :8;
    uint32              :3;
    uint32 RETBASE      :1;
    uint32 VECPEND      :3;
    uint32              :2;
    uint32 ISRPEND      :1;
    uint32 ISRPRE       :1;
    uint32              :1;
    uint32 PENDSTCLR    :1;
    uint32 PENDSTSET    :1;
    uint32 UNPENDSV     :1;
    uint32 PENDSV       :1;
    uint32              :2;
    uint32 NMISET       :1; 
}INTCTRL_BF;
typedef union 
{
    uint32     R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct
{
    uint32 VECTRESET    : 1;
    uint32 VECTCLRACT   : 1;
    uint32 SYSRESREQ    : 1;
    uint32              : 5;
    uint32 PRIGROUP     : 3;
    uint32 : 4;
    uint32 ENDIANESS    : 1;
    uint32 VECTKEY      : 16;
} APINT_BF;
typedef union
{
    uint32   R;
    APINT_BF B;
} APINT_TAG;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEX_M4_PERIPHERALS_BASE_ADDRESS 0xE000E000
#define APINT                        (*((volatile APINT_TAG *)(CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD0C)))
#define RCGCTIMER                    (*((volatile RCGCTIMER_Tag *)(RCGCTIMER_BASE_ADDRESS + RCGCTIMER_OFFSET)))
#define NVIC_ENX_BASE_ADDRESS        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x100)
#define NVIC_PRIX_BASE_ADDRESS       (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x400)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/