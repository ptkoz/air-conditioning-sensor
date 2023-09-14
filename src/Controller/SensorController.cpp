#include "Controller/SensorController.h"
#include <avr/sleep.h>
#include <avr/wdt.h>

using ACC::Controller::SensorController;

void ACC::Controller::SensorController::process() {
    if (sinceLastMeasure >= measureInterval) {
        if (humiditySensor) {
            float values[3] = {
                temperatureSensor.measureTemperature(),
                humiditySensor->measureHumidity(),
                voltageSensor.measureVoltage()
            };

            remoteExecutor.execute(recipientAddress, recipientCommand, values, 3 * sizeof values[0]);
        } else {
            float values[2] = {
                temperatureSensor.measureTemperature(),
                voltageSensor.measureVoltage()
            };

            remoteExecutor.execute(recipientAddress, recipientCommand, &values, 2 * sizeof(values));
        }

        sinceLastMeasure = 0;
    }
    // disable ADC
    ADCSRA = 0;

    // clear various "reset" flags
    MCUSR = 0;
    // allow changes, disable reset
    WDTCSR = bit (WDCE) | bit (WDE);
    // set interrupt mode and an interval
    WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 seconds delay
    wdt_reset();  // pat the dog

    set_sleep_mode (SLEEP_MODE_PWR_DOWN);
    noInterrupts ();           // timed sequence follows
    sleep_enable();

    // turn off brown-out enable in software
    MCUCR = bit (BODS) | bit (BODSE);
    MCUCR = bit (BODS);
    interrupts ();             // guarantees next instruction executed
    sleep_cpu ();

    // cancel sleep as a precaution
    sleep_disable();

    sinceLastMeasure += 8;
}

// watchdog interrupt
ISR (WDT_vect)
{
    wdt_disable();  // disable watchdog
}
