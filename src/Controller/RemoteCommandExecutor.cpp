#include "Controller/RemoteCommandExecutor.h"
#include "SoftwareSerial.h"

using ACC::Controller::RemoteCommand::Executor;

void Executor::execute(
    unsigned short address,
    unsigned short command,
    const void * message,
    size_t length
) {
    radio.wakeup();
    Stream & stream = radio.getStream();

    size_t shortLength = sizeof(unsigned short);
    unsigned char headerBuffer[2 * shortLength];

    radio.encode(headerBuffer, static_cast<const unsigned char *>(static_cast<const void *>(&address)), shortLength);
    stream.write(headerBuffer, 2 * shortLength);

    radio.encode(headerBuffer, static_cast<const unsigned char *>(static_cast<const void *>(&command)), shortLength);
    stream.write(headerBuffer, 2 * shortLength);

    unsigned char messageBuffer[2 * length];
    radio.encode(messageBuffer, static_cast<unsigned const char *>(message), length);
    stream.write(messageBuffer, 2 * length);
    stream.write((char) 0xFF);

    delay(200); // leave some time to send it

    radio.sleep();
}

