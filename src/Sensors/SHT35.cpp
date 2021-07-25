#include "Sensors/SHT35.h"

using namespace ACC::Sensors;

void SHT35::initialize() {
    sensor.begin(sensorAddress);
    sensor.heatOff();

    for (double & measure : temperatureMeasures) {
        sensor.read(true);
        measure = sensor.getTemperature();
    }

    for (double & measure : humidityMeasures) {
        sensor.read(true);
        measure = sensor.getHumidity();
    }
}

double SHT35::measureTemperature() {
    requestMeasurementFromSensor();
    temperatureMeasures[temperatureMeasureIndex++ % numberOfMeasures] = sensor.getTemperature();

    double sum = 0;
    for (double measure : temperatureMeasures) {
        sum += measure;
    }

    return sum / numberOfMeasures;
}

double SHT35::measureHumidity() {
    requestMeasurementFromSensor();
    humidityMeasures[humidityMeasureIndex++ % numberOfMeasures] = sensor.getHumidity();

    double sum = 0;
    for (double measure : humidityMeasures) {
        sum += measure;
    }

    return sum / numberOfMeasures;
}

void SHT35::requestMeasurementFromSensor() {
    sensor.read(false);
}



