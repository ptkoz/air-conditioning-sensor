#ifndef AIR_CONDITIONING_SENSOR_TEMPERATURESENSOR_H
#define AIR_CONDITIONING_SENSOR_TEMPERATURESENSOR_H

namespace ACC { namespace Sensors {
    /**
     * An abstract temperature sensor
     */
    class TemperatureSensor {
        public:
            virtual double measureTemperature() = 0;
    };
} }

#endif //AIR_CONDITIONING_SENSOR_TEMPERATURESENSOR_H
