#ifndef AIR_CONDITIONING_SENSOR_REMOTECOMMANDEXECUTOR_H
#define AIR_CONDITIONING_SENSOR_REMOTECOMMANDEXECUTOR_H

#include "Arduino.h"
#include "RemoteCommandRadio.h"

namespace ACC { namespace Controller { namespace RemoteCommand {
    /**
     * Interface for executing remote commands
     */
     class Executor {
         private:
             Radio & radio;
         public:
             explicit Executor(Radio & radio):
                radio(radio) {}

             void execute(
                 unsigned short address,
                 unsigned short command,
                 const void * message = nullptr,
                 size_t length = 0
             );
     };
} } }

#endif //AIR_CONDITIONING_SENSOR_REMOTECOMMANDEXECUTOR_H
