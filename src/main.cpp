#include <Arduino.h>
#include "Controller/SensorController.h"
#include "Sensors/VccVoltageSensor.h"

#define LIVING_ROOM 1
#define BEDROOM 2
#define OUTDOOR 3
#define VARIANT BEDROOM

ACC::Controller::RemoteCommand::Radio radio(Serial, 2);
ACC::Sensors::VccVoltageSensor vccVoltageSensor;

#if VARIANT == OUTDOOR
    #include "Sensors/MCP9808.h"
    ACC::Sensors::MCP9808 mcp9808(0x18);
    ACC::Controller::SensorController controller(radio, mcp9808, vccVoltageSensor, nullptr, 0xA1, 0x41, 600);
#elif VARIANT == BEDROOM
    #include "Sensors/SHT35.h"
    ACC::Sensors::SHT35 sht35(0x45);
    ACC::Controller::SensorController controller(radio, sht35, vccVoltageSensor, &sht35, 0xA1U, 0x21U, 60);
#elif VARIANT == LIVING_ROOM
    #include "Sensors/SHT35.h"
    ACC::Sensors::SHT35 sht35(0x45);
    ACC::Controller::SensorController controller(radio, sht35, vccVoltageSensor, &sht35, 0xA1U, 0x20U, 60);
#endif

void setup() {
    // Disable internal led for power saving
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.begin(4800);
    radio.initialize();
#if VARIANT == OUTDOOR
    mcp9808.initialize();
#elif VARIANT == BEDROOM or VARIANT == LIVING_ROOM
    sht35.initialize();
#endif
}

void loop() {
    controller.process();
}
