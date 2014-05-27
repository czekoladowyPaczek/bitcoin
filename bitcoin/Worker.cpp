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
	char buff[2048];
	int position;
	int oldPosition;
	while(running){
		int size = socket.receiveBytes(buff, 2048);
		std::string message(buff, size);
		std::cout << message << std::endl;
		position = 0;
		oldPosition = 0;
		do{
			position = message.find('\n', position) + 1;

			if(listener){
				listener->onMessage(new BitcoinMessage(message.substr(oldPosition, position - oldPosition)));
			}
			oldPosition = position;
		} while(position != message.length());
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