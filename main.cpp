#include "mbed.h"
#include <iostream>
#include "elrs_receiver.hpp"

int main(void)
{
    //initialize reciever
    elrc_receiver theReciever(PB_9, PB_8);
    while(1){
        //gather data and if data got updated, then print values
        if(theReciever.gatherData()){
            for(int i = 0; i < 8; i++){
                printf("%d ", theReciever.busData()[i]);
            }
            printf("\n");
        }
        else {
            printf("no message\n");
        }
        ThisThread::sleep_for(100ms);
    }
}