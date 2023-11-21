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

DigitalOut myled(LED1);
InterruptIn mybtn(BUTTON1);
I2C bus(I2C1_SDA, I2C1_SCL);
BME280 bme = BME280(&bus,BME280::I2CAddress::Address1);
int main()
{
        bme.initialize();
        bme.set_sampling(BME280::SensorMode::NORMAL,BME280::SensorSampling::OVERSAMPLING_X1,BME280::SensorSampling::OVERSAMPLING_X1,BME280::SensorSampling::OVERSAMPLING_X1,BME280::SensorFilter::OFF,BME280::StandbyDuration::MS_0_5);
        
        while (1)
        {
                float Hum = bme.humidity();
                ThisThread::sleep_for(500);
                printf("Humidite : %.2f %\n",Hum);
                float Temp = bme.temperature();
                ThisThread::sleep_for(500);
                printf("Temperature : %.2f C\n",Temp);
                float Pres = bme.pressure();
                ThisThread::sleep_for(500);
                printf("Pression : %.2f Bar\n",Pres/100000);
                ThisThread::sleep_for(PERIOD_MS);
        }
}
