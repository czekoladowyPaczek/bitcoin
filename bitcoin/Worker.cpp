#include "Worker.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include "MessageFactory.h"
Worker::Worker(void): socketAddr(SERVER_ADDR){
	running = true;
	listener = NULL;
}

Worker::~Worker(void){

}

void Worker::run(){
	socket.connect(socketAddr);
	if(listener){
		listener->onMessage(new BitcoinMessage("22", 2));
	}
	char buff[1024];
	while(running){
		int size = socket.receiveBytes(buff, 2048);
		if(listener){
			listener->onMessage(new BitcoinMessage(buff, size));
		}
	}
}

void Worker::stop(){
	running = false;

	socket.close();
}

void Worker::sendMessage(std::string message){
	socket.sendBytes(message.c_str(), message.length());
}

void Worker::setListener(MessageListener* listener){
	this->listener = listener;
}