#pragma once

namespace ACC::Sensors {
    /**
     * An abstract humidity sensor
     */
    class HumiditySensor {
        public:
            virtual float measureHumidity() = 0;
    };
}
