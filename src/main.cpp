#include <Arduino.h>
#include "Controller/RemoteCommandExecutor.h"
#include "Controller/SensorController.h"

#define INDOOR 1
#define OUTDOOR 2
#define VARIANT OUTDOOR

ACC::Controller::RemoteCommand::Executor executor(Serial, 2);

#if VARIANT == OUTDOOR
    #include "Sensors/MCP9808.h"
    ACC::Sensors::MCP9808 mcp9808(0x18);
    ACC::Controller::SensorController controller(executor, mcp9808, nullptr, 0xA1, 0x41);
#elif VARIANT == INDOOR
    #include "Sensors/SHT35.h"
    ACC::Sensors::SHT35 sht35(0x45);
    ACC::Controller::SensorController controller(executor, sht35, &sht35, 0xA1U, 0x21U);
#endif

void setup() {
    Serial.begin(9600);
    executor.initialize();
#if VARIANT == OUTDOOR
    mcp9808.initialize();
#elif VARIANT == INDOOR
    sht35.initialize();
#endif
}

void loop() {
    controller.process();
}
