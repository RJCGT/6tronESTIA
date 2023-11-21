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
I2C bus(I2C1_SDA,I2C1_SCL);
const int addr7bit = 0x76;      // 7 bit I2C address
const int addr8bit = 0x76 << 1; // 8bit I2C address
char entre[2];
char retour[2];
float hum=0.00;
float temp=0.00;
float pres=0.00;

int main()
{
          
        while (1) {   

                entre[0] = 0xD0;
                bus.write(addr8bit,entre,1);
                ThisThread::sleep_for(500);
                bus.read(addr8bit,retour,1);
                float id = float(retour[0]);
                entre[0] = 0xF2;
                entre[1] =0b001;
                bus.write(addr8bit,entre,2);
                ThisThread::sleep_for(500);
                entre[0] = 0xF4;
                entre[1] =0x26;
                bus.write(addr8bit,entre,2);
                ThisThread::sleep_for(500);


                printf("ID = %.2f\n", id);
                ThisThread::sleep_for(PERIOD_MS);
                entre[0] = 0xFD;
                bus.write(addr8bit,entre,1);
                ThisThread::sleep_for(500);
                bus.read(addr8bit,retour,2); 
                hum = float(retour[0]<<8 | retour[1] << 4)/1024;
                printf("Hum = %.2f %\n", hum);
                entre[0] = 0xFA;
                bus.write(addr8bit,entre,1);
                ThisThread::sleep_for(500);
                bus.read(addr8bit,retour,3); 
                temp = float(retour[0]<<12 | retour[1] << 4 | retour[2]>>4)/100;
                printf("temp= %.2f C\n", temp);
                
                
        }
		
	
}
