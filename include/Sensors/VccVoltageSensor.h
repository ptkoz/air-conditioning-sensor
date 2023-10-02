#pragma once

#include "VoltageSensor.h"

namespace ACC::Sensors {
    /**
     * A voltage sensor measuring internal ADC voltage
     */
    class VccVoltageSensor : public VoltageSensor {
        public:
            float measureVoltage() override;
    };
}
