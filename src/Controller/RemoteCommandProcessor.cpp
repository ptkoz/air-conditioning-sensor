#include "Controller/RemoteCommandExecutor.h"

using ACC::Controller::RemoteCommand::Executor;

void Executor::initialize() {
    pinMode(setPin, OUTPUT);
    digitalWrite(setPin, LOW);

    stream.print("AT+C003");
    while (stream.read() != -1);

    stream.print("AT+FU1");
    while (stream.read() != -1);

    stream.print("AT+B9600");
    while (stream.read() != -1);

    pinMode(setPin, INPUT);
    digitalWrite(setPin, LOW);

    stream.setTimeout(1000);
}

void Executor::execute(
    unsigned short address,
    unsigned short command,
    const void * message,
    size_t length
) {
    stream.write(static_cast<const char *>(static_cast<const void *>(&address)), sizeof address);
    stream.write(static_cast<const char *>(static_cast<const void *>(&command)), sizeof command);
    stream.write(static_cast<const char *>(message), length);
    stream.write((char) 0);
}
