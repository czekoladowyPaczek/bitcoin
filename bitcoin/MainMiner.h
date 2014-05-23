#pragma once

#include "Worker.h"
#include "MessageListener.h"
#include "BitcoinMessage.h"

class MainMiner: public MessageListener
{
public:
	MainMiner(void);
	~MainMiner(void);

	void start();
	void stop();
	void onMessage(BitcoinMessage* message);
private:
	Worker serverThread;
};

