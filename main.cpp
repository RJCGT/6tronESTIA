/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "bme280.h"

using namespace sixtron;
using namespace std::chrono;
namespace
{
#define PERIOD_MS 2000ms
}
DigitalOut led1(LED1);
Thread thread1;
Thread thread2;

void ping(){
        for(int i=0; i<100;i++){
                printf("Ping\n");
                ThisThread::sleep_for(500);
        }
}

void pong(){
        for(int i=0; i<100;i++){
                printf("Pong\n");
                ThisThread::sleep_for(500);
        }
}

int main()
{
        thread1.start(ping);
        thread2.start(pong);
        while(1){
                led1 = !led1;
                printf("Alive !\n");
                ThisThread::sleep_for(PERIOD_MS);
        }
        
}
