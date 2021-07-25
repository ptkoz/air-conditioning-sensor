#ifndef AIR_CONDITIONING_SENSOR_SHT35_H
#define AIR_CONDITIONING_SENSOR_SHT35_H

#include <SHT31.h>
#include "Sensors/TemperatureSensor.h"
#include "Sensors/HumiditySensor.h"

namespace ACC { namespace Sensors {
    /**
     * An SHT35 temperature & humidity sensor
     */
    class SHT35 : public TemperatureSensor, public HumiditySensor {
        private:
            static constexpr unsigned char numberOfMeasures = 3;

            uint8_t sensorAddress;
            SHT31 sensor;

            unsigned char temperatureMeasureIndex = 0;
            double temperatureMeasures[numberOfMeasures] = {};

            unsigned char humidityMeasureIndex = 0;
            double humidityMeasures[numberOfMeasures] = {};

            void requestMeasurementFromSensor();
        public:
            explicit SHT35(uint8_t sensorAddress):
                sensorAddress(sensorAddress) {}

            void initialize();
            double measureTemperature() override;
            double measureHumidity() override;
    };
} }

#endif //AIR_CONDITIONING_SENSOR_SHT35_H
