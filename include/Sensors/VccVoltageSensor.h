#ifndef AIR_CONDITIONING_SENSOR_VCCVOLTAGESENSOR_H
#define AIR_CONDITIONING_SENSOR_VCCVOLTAGESENSOR_H

#include "VoltageSensor.h"

namespace ACC { namespace Sensors {
        /**
         * A voltage sensor measuring internal ADC voltage
         */
        class VccVoltageSensor : public VoltageSensor {
            public:
                float measureVoltage();
        };
    } }

#endif //AIR_CONDITIONING_SENSOR_VCCVOLTAGESENSOR_H
