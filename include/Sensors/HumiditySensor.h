#ifndef AIR_CONDITIONING_SENSOR_HUMIDITYSENSOR_H
#define AIR_CONDITIONING_SENSOR_HUMIDITYSENSOR_H

namespace ACC { namespace Sensors {
    /**
     * An abstract temperature sensor
     */
    class HumiditySensor {
        public:
            virtual double measureHumidity() = 0;
    };
} }

#endif //AIR_CONDITIONING_SENSOR_TEMPERATURESENSOR_H
