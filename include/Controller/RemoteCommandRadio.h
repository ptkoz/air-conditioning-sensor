#ifndef AIR_CONDITIONING_SENSOR_REMOTECOMMANDRADIO_H
#define AIR_CONDITIONING_SENSOR_REMOTECOMMANDRADIO_H

#include <Stream.h>

namespace ACC { namespace Controller { namespace RemoteCommand {
    /**
     * Radio abstraction layer for processor & executor
     */
    class Radio {
        private:
            Stream & stream;
            const unsigned char setPin;

            void enterATMode();
            void leaveATMode();
        public:
            Radio(Stream & stream, unsigned char setPin):
                stream(stream),
                setPin(setPin) {}

            void initialize();

            void sleep();
            void wakeup();

            Stream & getStream() const {
                return stream;
            }
    };
} } }

#endif //AIR_CONDITIONING_SENSOR_REMOTECOMMANDRADIO_H
