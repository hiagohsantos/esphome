#include "esphome/core/log.h"
#include "jsn-sro4t.h"

namespace esphome {
namespace jsn-sro4t {

static const char *TAG = "jsn-sro4t.sensor";

void EmptySensor::setup() {
    // This will be called by App.setup()
    pinMode(TRIG, OUTPUT);       // Initializing Trigger Output
    pinMode(ECHO, INPUT_PULLUP); // Initializing Echo Input
  
}

void EmptySensor::loop() {
  
}

void EmptySensor::update() {

}

void EmptySensor::dump_config() {
    ESP_LOGCONFIG(TAG, "jsn-sro4t ultrasonic sensor");
}

} //namespace empty_sensor
} //namespace esphome