#include "Sensors/MCP9808.h"

using ACC::Sensors::MCP9808;

void MCP9808::initialize() {
    sensor.begin(sensorAddress);
    sensor.setResolution(0);

    for (double & measure : measures) {
        measure = sensor.readTempC();
    }
}

double MCP9808::measureTemperature() {
    measures[measureIndex++ % numberOfMeasures] = sensor.readTempC();

    double sum = 0;
    for (double measure : measures) {
        sum += measure;
    }

    return sum / numberOfMeasures;
}



