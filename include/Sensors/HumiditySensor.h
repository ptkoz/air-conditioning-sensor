#ifndef AIR_CONDITIONING_SENSOR_HUMIDITYSENSOR_H
#define AIR_CONDITIONING_SENSOR_HUMIDITYSENSOR_H

namespace ACC::Sensors {
    /**
     * An abstract humidity sensor
     */
    class HumiditySensor {
        public:
            virtual float measureHumidity() = 0;
    };
}

#endif //AIR_CONDITIONING_SENSOR_TEMPERATURESENSOR_H
