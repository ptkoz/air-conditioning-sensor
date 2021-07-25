#ifndef AIR_CONDITIONING_SENSOR_REMOTECOMMANDEXECUTOR_H
#define AIR_CONDITIONING_SENSOR_REMOTECOMMANDEXECUTOR_H

#include "Arduino.h"

namespace ACC { namespace Controller { namespace RemoteCommand {
    /**
     * Interface for executing remote commands
     */
     class Executor {
         private:
             Stream & stream;
             const unsigned char setPin;
         public:
             Executor(Stream & stream, unsigned char setPin):
                stream(stream),
                setPin(setPin) {}

             void initialize();

             void execute(
                 unsigned short address,
                 unsigned short command,
                 const void * message = nullptr,
                 size_t length = 0
             );
     };
} } }

#endif //AIR_CONDITIONING_SENSOR_REMOTECOMMANDEXECUTOR_H
