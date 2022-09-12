#include "GPT.h"

Timer_Init(TimerConf timer)
{
    
    // Initialize Timer Using Timer Number and Number Of Counts

}



ISR(){
    static int count = 0;
    if(count == 1){
        //CallBack Functuin To Send Speed Sensor
    }
    else if(count == 2){
        //CallBack Functuin To Send Speed Sensor Value
        //CallBack Functuin To Send Door Sensor Value
    }
    else if(count == 4){
        //CallBack Functuin To Send Speed Sensor Value
        //CallBack Functuin To Send Door Sensor Value
        //CallBack Functuin To Send Light Sensor Value
    }

    count++;
}