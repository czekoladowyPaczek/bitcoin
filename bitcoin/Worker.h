#pragma once

#include <iostream>
#include <Poco\Thread.h>
#include <Poco\Net\StreamSocket.h>
#include <Poco\Net\SocketAddress.h>
#include "MessageListener.h"

class Worker: public Poco::Runnable
{
public:
	Worker(void);
	~Worker(void);

	virtual void run();
	void stop();
	void sendMessage(std::string message);
	void setListener(MessageListener* listener);

private:
	Poco::Net::StreamSocket socket;
	Poco::Net::SocketAddress socketAddr;
	bool running;
	MessageListener* listener;
};

