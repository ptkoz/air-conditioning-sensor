#include <Arduino.h>
#include "Controller/RemoteCommandRadio.h"

void ACC::Controller::RemoteCommand::Radio::initialize() {
    enterATMode();

    stream.println("AT+C003");
    delay(80);
    stream.println("AT+FU3");
    delay(80);
    stream.println("AT+P8");
    delay(80);
    stream.println("AT+B4800");
    delay(80);

    while (stream.available()) {
        stream.read();
    }

    leaveATMode();

    stream.setTimeout(1000);
}

void ACC::Controller::RemoteCommand::Radio::enterATMode() const {
    pinMode(setPin, OUTPUT);
    digitalWrite(setPin, LOW);
    delay(40);
}

void ACC::Controller::RemoteCommand::Radio::leaveATMode() const {
    pinMode(setPin, INPUT);
    digitalWrite(setPin, LOW);
    delay(80);
}

void ACC::Controller::RemoteCommand::Radio::sleep() {
    enterATMode();

    stream.print("AT+SLEEP");
    delay(80);
    while (stream.available()) {
        stream.read();
    }

    leaveATMode();
}

void ACC::Controller::RemoteCommand::Radio::wakeup() {
    enterATMode();
    leaveATMode();
}

void ACC::Controller::RemoteCommand::Radio::send(const ACC::Controller::RemoteCommand::OutboundMessage &message) {
    wakeup();

    stream.write(message.getEncodedData(), message.getDataLength());

    delay(1000); // leave some time to send it
    sleep();
}
