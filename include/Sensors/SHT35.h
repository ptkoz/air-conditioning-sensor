#ifndef AIR_CONDITIONING_SENSOR_SHT35_H
#define AIR_CONDITIONING_SENSOR_SHT35_H

#include <SHT31.h>
#include "Sensors/TemperatureSensor.h"
#include "Sensors/HumiditySensor.h"

namespace ACC::Sensors {
    /**
     * An SHT35 temperature & humidity sensor
     */
    class SHT35 : public TemperatureSensor, public HumiditySensor {
        private:
            uint8_t sensorAddress;
            SHT31 sensor;

            void requestMeasurementFromSensor();

        public:
            explicit SHT35(uint8_t sensorAddress) :
                sensorAddress(sensorAddress) {}

            void initialize();

            float measureTemperature() override;

            float measureHumidity() override;
    };
}

#endif //AIR_CONDITIONING_SENSOR_SHT35_H
