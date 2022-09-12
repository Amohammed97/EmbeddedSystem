#include "Comman\Std_Types.h"
#include "Comman\Macros.h"

typedef enum{

        Timer1,
        Timer2,
        Timer3,
        Timer4

}TimerNumber;


typedef struct
{
    TimerNumber Timer;
    uint32      Count;
}TimerConf;
