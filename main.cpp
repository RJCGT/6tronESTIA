/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

namespace {
#define PERIOD_MS 2000ms
}

DigitalOut myled(LED1);
InterruptIn mybtn(BUTTON1);
void flip(){
        myled = !myled;
}
int main()
{
        mybtn.rise(&flip);  
        while (1) {          // wait around, interrupts will interrupt this!
        ThisThread::sleep_for(250);
        }
		
	
}
