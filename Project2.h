#define Speed_Sensor    0x01
#define Door_Sensor     0x02
#define Light_Sensor    0x03


enum{
    PORTA,
    PORTB,
    PORTC,
    PORTD
}Port_Number;

enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}Pin_Number;

typedef struct
{
    Port_Number _port,
    Pin_Number  _Pin
}PortPinDir;


typedef struct{

}