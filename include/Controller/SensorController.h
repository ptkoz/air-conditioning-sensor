#pragma once

#include "Radio/Publisher.h"
#include "Sensors/TemperatureSensor.h"
#include "Sensors/VoltageSensor.h"
#include "Sensors/HumiditySensor.h"

namespace ACC::Controller {
    /**
     * Controller that controls this remote sensors behaviour.
     */
    class SensorController {
        private:
            Radio::Publisher &publisher;
            Sensors::TemperatureSensor &temperatureSensor;
            Sensors::VoltageSensor &voltageSensor;
            /** Humidity sensor is optional */
            Sensors::HumiditySensor *const humiditySensor;

            /** Where to send data */
            const unsigned short recipientAddress;
            const unsigned short recipientCommand;

            /** How often do we want to send reading? */
            const unsigned short measureInterval;
            /** How many seconds passed since last measure? */
            unsigned short sinceLastMeasure;
        public:
            SensorController(
                Radio::Publisher &publisher,
                Sensors::TemperatureSensor &temperatureSensor,
                Sensors::VoltageSensor &voltageSensor,
                Sensors::HumiditySensor *humiditySensor,
                unsigned short recipientAddress,
                const unsigned short recipientCommand,
                const unsigned short measureInterval
            ) :
                publisher(publisher),
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
}

