#include "Comman\Std_Types.h"
#include "Comman\Macros.h"

enum{
    Arbitration_Speed_Sensor_Code = 0x01,
    Arbitration_Door_Sensor_Code,
    Arbitration_Light_Sensor_Code,
}arbitration_Codes;


typedef struct 
{
    STD_levelType Door_Sensor;
    STD_levelType Light_Switch;
    STD_levelType Speed_Sensor;
}SensorsValues;


typedef struct {

    uint8              Unique_Code;
    STD_levelType       State;

}Sensor_Statuse;


void BMC_Init(void);
void BMC_Send(Sensor_Statuse  Message);
SensorsValues BMC_Recive(uint8 Sensor_Code);

