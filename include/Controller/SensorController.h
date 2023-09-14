#ifndef AIR_CONDITIONING_SENSOR_SENSORCONTROLLER_H
#define AIR_CONDITIONING_SENSOR_SENSORCONTROLLER_H

#include "Controller/RemoteCommandExecutor.h"
#include "Sensors/TemperatureSensor.h"
#include "Sensors/VoltageSensor.h"
#include "Sensors/HumiditySensor.h"

namespace ACC { namespace Controller {
    /**
     * Controller that controls this remote sensors behaviour.
     */
    class SensorController {
        private:
            RemoteCommand::Executor & remoteExecutor;
            Sensors::TemperatureSensor & temperatureSensor;
            Sensors::VoltageSensor & voltageSensor;
            /** Humidity sensor is optional */
            Sensors::HumiditySensor * const humiditySensor;

            /** Where to send data */
            const unsigned short recipientAddress;
            const unsigned short recipientCommand;

            /** How often do we want to send reading? */
            const unsigned short measureInterval;
            /** How many seconds passed since last measure? */
            unsigned short sinceLastMeasure;
        public:
            SensorController(
                RemoteCommand::Executor & remoteExecutor,
                Sensors::TemperatureSensor & temperatureSensor,
                Sensors::VoltageSensor & voltageSensor,
                Sensors::HumiditySensor * humiditySensor,
                unsigned short recipientAddress,
                const unsigned short recipientCommand,
                const unsigned short measureInterval
            ):
                remoteExecutor(remoteExecutor),
                temperatureSensor(temperatureSensor),
                voltageSensor(voltageSensor),
                humiditySensor(humiditySensor),
                recipientAddress(recipientAddress),
                recipientCommand(recipientCommand),
                measureInterval(measureInterval),
                sinceLastMeasure(measureInterval) // initialize with measure interval so we get reading straight away
                {}

            void process();
    };
} }

#endif //AIR_CONDITIONING_SENSOR_SENSORCONTROLLER_H
