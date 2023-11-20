/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

namespace {
#define PERIOD_MS 2000ms
}

DigitalOut myled(LED1);

int main()
{
	while (true) {
		printf("Alive! \n");
		myled = 1;          // set LED1 pin to high
        printf("myled = %d \n\r", (uint8_t)myled);
        ThisThread::sleep_for(500);

        myled.write(0);     // set LED1 pin to low
        printf("myled = %d \n\r", myled.read());
        
		ThisThread::sleep_for(PERIOD_MS / 2);
	}
}
