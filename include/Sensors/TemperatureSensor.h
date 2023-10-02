#pragma once

namespace ACC::Sensors {
    /**
     * An abstract temperature sensor
     */
    class TemperatureSensor {
        public:
            virtual float measureTemperature() = 0;
    };
}
