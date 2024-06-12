#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace jsn-sro4t {

class UltrasonicSensor : public sensor::Sensor, public PollingComponent {
    void setup() override
    {
    // This will be called by App.setup()
    pinMode(TRIG, OUTPUT);       // Initializing Trigger Output
    pinMode(ECHO, INPUT_PULLUP); // Initializing Echo Input
    };

    void loop() override;
    void update() override
    {
        // This will be called every "update_interval" milliseconds.
    digitalWrite(TRIG, LOW); 
    delayMicroseconds(2); 

    digitalWrite(TRIG, HIGH);  
    delayMicroseconds(20); 

    digitalWrite(TRIG, LOW);  

    int distance = pulseIn(ECHO, HIGH, 26000);  

    distance= distance/58; 
    publish_state(distance);
    };

    void dump_config() override;
};

} 
} 