#pragma once

namespace ACC::Sensors {
    /**
     * An abstract temperature sensor
     */
    class VoltageSensor {
        public:
            virtual float measureVoltage() = 0;
    };
}
