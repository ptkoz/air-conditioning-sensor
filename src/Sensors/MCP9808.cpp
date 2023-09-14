#include "Sensors/MCP9808.h"

using ACC::Sensors::MCP9808;

void MCP9808::initialize() {
    sensor.begin(sensorAddress);
    sensor.setResolution(0);
}

float MCP9808::measureTemperature() {
    sensor.wake();
    float measure = sensor.readTempC();
    sensor.shutdown();

    return measure;
}



