#pragma once

#include <string>
#include "BitcoinMessage.h"

class MessageListener
{
public:
	MessageListener(void);
	~MessageListener(void);

	virtual void onMessage(BitcoinMessage* message) = 0;
};

