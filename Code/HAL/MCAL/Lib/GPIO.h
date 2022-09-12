#include "Comman\Std_Types.h"
#include "Comman\Macros.h"
typedef enum{
    INPUT,
    OUTPUT
}Direction_Pin;

typedef enum{
    PORTA,
    PORTB,
    PORTC,
    PORTD
}Port_Number;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}Pin_Number;

typedef struct  {
    Pin_Number      pin;
    Direction_Pin   Dir;
}Pin_Dir;

typedef struct 
{
    Port_Number port;
    Pin_Dir     Config[7];
}PortPinDir;

typedef struct{
    uint_8 Pin_Number;
    Port_Number Port;
}SensorPin;

// int main() {
//     // Write C code here
//     struct PortPinDir GPIO[4] = 
//     {   
//         {
//             PORTA,
//             {
//                 {PIN0,OUTPUT},
//                 {PIN1,INPUT},
//                 {PIN2,OUTPUT},
//                 {PIN3,INPUT},
//                 {PIN4,OUTPUT},
//                 {PIN5,INPUT},
//                 {PIN6,OUTPUT},
//                 {PIN7,INPUT}
//             }
//         },
//         {
//             PORTB,
//             {
//                 {PIN0,OUTPUT},
//                 {PIN1,INPUT},
//                 {PIN2,OUTPUT},
//                 {PIN3,INPUT},
//                 {PIN4,OUTPUT},
//                 {PIN5,INPUT},
//                 {PIN6,OUTPUT},
//                 {PIN7,INPUT}
//             }
//         }
        
//     };

    

    
//     return 0;
// }