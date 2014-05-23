#include "MainMiner.h"

#include "Worker.h"
#include "MessageFactory.h"
#include <Poco\Thread.h>

MainMiner::MainMiner(void){
	serverThread.setListener(this);
}


MainMiner::~MainMiner(void){

}

void MainMiner::start(){
	Poco::Thread thread;
	thread.start(serverThread);

}

void MainMiner::stop(){
	serverThread.stop();
}

void MainMiner::onMessage(BitcoinMessage* message){
	if(message->getMessage().length() == 2){
		std::string msg = MessageFactory::getConnectMessage();
		serverThread.sendMessage(msg);
	}
	std::cout << "dostalem wiadomosc: " << message->getMessage() << std::endl;
}