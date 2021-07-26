#include "Controller/RemoteCommandExecutor.h"
#include "SoftwareSerial.h"

using ACC::Controller::RemoteCommand::Executor;

void Executor::execute(
    unsigned short address,
    unsigned short command,
    const void * message,
    size_t length
) {
    Stream & stream = radio.getStream();
    stream.write(static_cast<const char *>(static_cast<const void *>(&address)), sizeof address);
    stream.write(static_cast<const char *>(static_cast<const void *>(&command)), sizeof command);
    stream.write(static_cast<const char *>(message), length);
    stream.write((char) 0);
}

