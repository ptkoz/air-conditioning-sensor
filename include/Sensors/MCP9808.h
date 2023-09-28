#ifndef AIR_CONDITIONING_SENSOR_MCP9808_H
#define AIR_CONDITIONING_SENSOR_MCP9808_H

#include "TemperatureSensor.h"
#include <Adafruit_MCP9808.h>

namespace ACC::Sensors {
    /**
     * A MCP9808 temperature sensor
     */
    class MCP9808 : public TemperatureSensor {
        private:
            uint8_t sensorAddress;
            Adafruit_MCP9808 sensor;
        public:
            explicit MCP9808(uint8_t sensorAddress) :
                sensorAddress(sensorAddress) {}

            void initialize();

            float measureTemperature() override;
    };
}

#endif //AIR_CONDITIONING_SENSOR_MCP9808_H
