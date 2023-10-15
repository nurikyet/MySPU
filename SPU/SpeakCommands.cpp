#define TX_USE_SPEAK
#include "TxLib.h"

#include"SpeakCommands.h"

void ProcessorBotay()
    {
    txSpeak("Пора ботать!");
    }

//-----------------------------------------------------------------------------

void ProcessorSleep()
    {
    txSpeak("Я хочу спать, но надо ботать...");
    }

//-----------------------------------------------------------------------------

void ProcessorDeadline()
    {
    txSpeak("Горит дедлайн!!!");
    }
