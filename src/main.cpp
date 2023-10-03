#include <Arduino.h>
#include "Controller/SensorController.h"
#include "Sensors/VccVoltageSensor.h"
#include "Radio/Radio.h"
#include "Security/NounceProvider.h"

#define MASTER_ADDRESS 0x10U
#define LIVING_ROOM 0x20U
#define BEDROOM 0x21U
#define OUTDOOR 0x41U
#define VARIANT BEDROOM

ACC::Security::NounceProvider nounceProvider;
ACC::Radio::Radio radio(Serial, 2, VARIANT, nounceProvider);  // NOLINT(*-interfaces-global-init)
ACC::Sensors::VccVoltageSensor vccVoltageSensor;

#if VARIANT == OUTDOOR
    #include "Sensors/MCP9808.h"
    ACC::Sensors::MCP9808 sensor(0x18);
    ACC::Controller::SensorController controller(publisher, mcp9808, vccVoltageSensor, nullptr, 0xA1, 0x41, 600);
#elif VARIANT == BEDROOM or VARIANT == LIVING_ROOM
    #include "Sensors/SHT35.h"
    ACC::Sensors::SHT35 sensor(0x45);
    ACC::Controller::SensorController controller(radio, sensor, vccVoltageSensor, &sensor, MASTER_ADDRESS, 0x01U, 60);
#endif

void setup() {
    // Disable internal led for power saving
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.begin(4800);
    radio.initialize();
    sensor.initialize();

    ACC::Security::NounceRegistry nounceRegistry;
    nounceProvider.initialize(radio, nounceRegistry, MASTER_ADDRESS, 0x00U);
}

void loop() {
    controller.process();
}
