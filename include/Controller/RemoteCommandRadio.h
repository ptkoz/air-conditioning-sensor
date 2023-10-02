#pragma once

#include <Stream.h>
#include "OutboundMessage.h"

namespace ACC::Controller::RemoteCommand {
    /**
     * Radio abstraction layer for processor & executor
     */
    class Radio {
        private:
            Stream &stream;
            const unsigned char setPin;

            void enterATMode() const;

            void leaveATMode() const;

            void sleep();

            void wakeup();

        public:
            Radio(Stream &stream, unsigned char setPin) :
                stream(stream),
                setPin(setPin) {}

            void initialize();

            void send(const OutboundMessage &message);


            Stream &getStream() const {
                return stream;
            }
    };
}
