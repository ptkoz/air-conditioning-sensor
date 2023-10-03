#include "Security/NounceProvider.h"
#include "InboundProcessor/InitializationProcessor.h"
#include "Radio/Radio.h"
#include "Time/Timestamp.h"

using namespace ACC::Security;

void NounceProvider::initialize(
    Radio::Radio &radio,
    NounceRegistry &nounceRegistry,
    unsigned char sendRequestTo,
    unsigned char requestCommand
) {
    InboundProcessor::InitializationProcessor initializationProcessor(*this, nounceRegistry);
    radio.enableReceiving();

    while (!isInitialized) {
        radio.send(sendRequestTo, requestCommand);
        Time::Timestamp receivingStartTimestamp;
        while (!isInitialized && receivingStartTimestamp.getMinAgeSeconds() < 15) {
            radio.receive(initializationProcessor);
        }
    }

    radio.disableReceiving();
}

void NounceProvider::finalizeInitialization(unsigned long inboundNounce, unsigned long outboundNounce) {

        isInitialized = true;
        lastInboundNounce = inboundNounce;
        lastOutboundNounce = outboundNounce;
}
