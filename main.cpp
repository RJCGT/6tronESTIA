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
Mutex mute;
Thread thread1;
Thread thread2;

void ping(){
        for(int i=0; i<100;i++){
                mute.lock();
                printf("Ping\n");
                mute.unlock();
                
        }
}

void pong(){
        for(int i=0; i<100;i++){
                mute.lock();
                printf("Pong\n");
                mute.unlock();
                
        }
}

int main()
{
        thread1.start(ping);
        thread2.start(pong);
        while(1){
                led1 = !led1;
                mute.lock();
                printf("Alive !\n");
                mute.unlock();
                ThisThread::sleep_for(500);
        }
        
}
