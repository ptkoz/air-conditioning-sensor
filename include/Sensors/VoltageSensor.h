#ifndef AIR_CONDITIONING_SENSOR_VOLTAGESENSOR_H
#define AIR_CONDITIONING_SENSOR_VOLTAGESENSOR_H

namespace ACC::Sensors {
    /**
     * An abstract temperature sensor
     */
    class VoltageSensor {
        public:
            virtual float measureVoltage() = 0;
    };
}

#endif //AIR_CONDITIONING_SENSOR_VOLTAGESENSOR_H
