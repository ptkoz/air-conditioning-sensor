#pragma once

#include "Stream.h"
#include "Publisher.h"
#include "InboundProcessor/InboundProcessor.h"

namespace ACC::Security {
    class NounceProvider; // forward declaration
}

namespace ACC::Radio {
    /**
     * Radio abstraction layer for processor & publisher
     */
    class Radio : public Publisher {
        private:
            Stream &stream;
            Security::NounceProvider &nounceProvider;
            const unsigned char setPin;
            const unsigned char ownAddress;
            bool receivingEnabled;

            /** Enters HC-12 module into configuration mode */
            void enterATMode();

            /** Exits HC-12 configuration mode */
            void leaveATMode();

            /** Put module to sleep */
            void sleep();

            /** Wake up the module */
            void wakeup();

        public:
            Radio(
                Stream &stream,
                unsigned char setPin,
                unsigned char ownAddress,
                Security::NounceProvider &nounceProvider
            ) :
                stream(stream),
                nounceProvider(nounceProvider),
                setPin(setPin),
                ownAddress(ownAddress),
                receivingEnabled(false) {}

            void initialize();

            void send(
                unsigned char toAddress,
                unsigned char command,
                const void *extendedBytes,
                unsigned char extendedBytesLength
            ) override;

            using Publisher::send;
            void enableReceiving();
            void receive(InboundProcessor::InboundProcessor &processor);
            void disableReceiving();
    };
}
