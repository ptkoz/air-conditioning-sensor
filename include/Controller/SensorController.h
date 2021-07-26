#ifndef AIR_CONDITIONING_SENSOR_SENSORCONTROLLER_H
#define AIR_CONDITIONING_SENSOR_SENSORCONTROLLER_H

#include "Controller/RemoteCommandExecutor.h"
#include "Sensors/TemperatureSensor.h"
#include "Sensors/HumiditySensor.h"

namespace ACC { namespace Controller {
    /**
     * Controller that controls this remote sensors behaviour.
     */
    class SensorController {
        private:
            /** How often do we want to send reading? */
            static constexpr unsigned short measureInterval = 600;
            /** How many seconds passed since last measure? Initialize with limit, so we get first measure straight away */
            unsigned short sinceLastMeasure = measureInterval;

            RemoteCommand::Executor & remoteExecutor;
            Sensors::TemperatureSensor & temperatureSensor;
            /** Humidity sensor is optional */
            Sensors::HumiditySensor * const humiditySensor;

            /** Where to send data */
            const unsigned short recipientAddress;
            const unsigned short recipientCommand;
        public:
            SensorController(
                RemoteCommand::Executor & remoteExecutor,
                Sensors::TemperatureSensor & temperatureSensor,
                Sensors::HumiditySensor * humiditySensor,
                unsigned short recipientAddress,
                const unsigned short recipientCommand
            ):
                remoteExecutor(remoteExecutor),
                temperatureSensor(temperatureSensor),
                humiditySensor(humiditySensor),
                recipientAddress(recipientAddress),
                recipientCommand(recipientCommand) {}

            void process();
    };
} }

#endif //AIR_CONDITIONING_SENSOR_SENSORCONTROLLER_H
