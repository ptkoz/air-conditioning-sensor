#include "Controller/SensorController.h"

using ACC::Controller::SensorController;

void ACC::Controller::SensorController::process() {
    if (humiditySensor) {
        double values[2] = {
            temperatureSensor.measureTemperature(),
            humiditySensor->measureHumidity()
        };

        remoteExecutor.execute(recipientAddress, recipientCommand, values, 2 * sizeof values[0]);
    } else {
        double value = temperatureSensor.measureTemperature();
        remoteExecutor.execute(recipientAddress, recipientCommand, &value, sizeof(value));
    }

    delay(measureInterval);
}
