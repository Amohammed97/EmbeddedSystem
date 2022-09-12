#include"BMC.h"



void BMC_Init(){

}

void BMC_Send(Sensor_Statuse  Message){
    //Send Message.Unique_Code as arbitration 
    //Send Message.State as Data
}

SensorsValues BMC_Recive(uint8 Sensor_Code){

    SensorsValues Values ;
    
    //if Arbitration == Arbitration_Door_Sensor_Code
    // Values.Door_Sensor = STD_HIGH;
    // or
    // Values.Door_Sensor = STD_LOW;

    //if Arbitration == Arbitration_Speed_Sensor_Code
    // Values.Speed_Sensor = STD_HIGH;
    // or
    // Values.Speed_Sensor = STD_LOW;

    //if Arbitration == Arbitration_Light_Sensor_Code
    // Values.Light_Sensor = STD_HIGH;
    // or
    // Values.Light_Sensor = STD_LOW;

    return Values;
}


