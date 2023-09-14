#include "Sensors/SHT35.h"

using namespace ACC::Sensors;

void SHT35::initialize() {
    sensor.begin(sensorAddress);
    sensor.heatOff();
}

float SHT35::measureTemperature() {
    requestMeasurementFromSensor();
    return sensor.getTemperature();
}

float SHT35::measureHumidity() {
    requestMeasurementFromSensor();
    return sensor.getHumidity();
}

void SHT35::requestMeasurementFromSensor() {
    sensor.read(false);
}



