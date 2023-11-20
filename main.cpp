/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

namespace {
#define PERIOD_MS 2000ms
}

DigitalOut myled(LED1);
DigitalIn mybtn(BUTTON1);

int main()
{
	if (mybtn.is_connected()) {
        printf("mypin is connected and initialized! \n\r");
    }

    // Optional: set mode as PullUp/PullDown/PullNone/OpenDrain
    mybtn.mode(PullNone);

    // press the button and see the console / led change
   
        
    
	while (true) {

        printf("myled = %d \n\r", myled.read());
        printf("mypin has value : %d \n\r", mybtn.read());
        myled = mybtn; // toggle led based on value of button
        ThisThread::sleep_for(250);

		
	}
}
