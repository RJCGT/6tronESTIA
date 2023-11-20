/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

using namespace std::chrono;
namespace {
#define PERIOD_MS 2000ms
}

DigitalOut myled(LED1);
InterruptIn mybtn(BUTTON1);
Timer t;


void haut(){
        myled = !myled;
        t.reset();
        t.start();
}

void bas(){
        myled = !myled;
        t.stop();
}
int main()
{
        mybtn.rise(&haut);  
        mybtn.fall(&bas);
        while (1) {          // wait around, interrupts will interrupt this!
        printf("Temps de pression: %llu \n",duration_cast<milliseconds>(t.elapsed_time()).count());
        ThisThread::sleep_for(PERIOD_MS);
        }
		
	
}
