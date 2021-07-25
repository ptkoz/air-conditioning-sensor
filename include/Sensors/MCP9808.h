#ifndef AIR_CONDITIONING_SENSOR_MCP9808_H
#define AIR_CONDITIONING_SENSOR_MCP9808_H

#include "TemperatureSensor.h"
#include <Adafruit_MCP9808.h>

#define MCP9808_NUMBER_OF_TEMPERATURE_MEASURES 10

namespace ACC { namespace Sensors {
    class MCP9808 : public TemperatureSensor {
        private:
            static constexpr unsigned char numberOfMeasures = 6;

            uint8_t sensorAddress;
            Adafruit_MCP9808 sensor;

            unsigned char measureIndex;
            double measures[numberOfMeasures];
        public:
            explicit MCP9808(uint8_t sensorAddress):
                sensorAddress(sensorAddress) {}

            void initialize();
            double measureTemperature() override;
    };
} }

#endif //AIR_CONDITIONING_SENSOR_MCP9808_H
