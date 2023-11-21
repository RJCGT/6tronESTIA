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
#define PERIOD_MS 1000ms
}

I2C bus(I2C1_SDA, I2C1_SCL);
BME280 bme = BME280(&bus,BME280::I2CAddress::Address1);

DigitalOut led1(LED1);
InterruptIn btn(BUTTON1);
Mutex mute;
EventQueue queue;
Thread t1;
float pres = 0.00;

void pression(){
        pres = bme.pressure();
        printf("Pressure : %.2f Pa \n",pres);
}
void pressionhandle(){
        queue.call(pression);
}



void temphum(){
        float temp = bme.temperature();
        printf("Temperature : %.2f °C \n",temp);
        float hum = bme.humidity();
        printf("Humidity : %.2f % \n",hum);
        
}

void clignote(){
        led1 = !led1;        
}


int main()
{
        bme.initialize();
        bme.set_sampling(BME280::SensorMode::NORMAL,BME280::SensorSampling::OVERSAMPLING_X1,BME280::SensorSampling::OVERSAMPLING_X1,BME280::SensorSampling::OVERSAMPLING_X1,BME280::SensorFilter::OFF,BME280::StandbyDuration::MS_0_5);
                
        t1.start(callback(&queue,&EventQueue::dispatch_forever));
        queue.call_every(5*PERIOD_MS,clignote);
        queue.call_every(2*PERIOD_MS,temphum);
        btn.rise(pressionhandle);
}
