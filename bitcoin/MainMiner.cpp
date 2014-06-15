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
	switch(message->getType()){
	case MESSAGE_TYPE::CONNECTED:
		std::cout << "connected" << std::endl;
		extraNonce1 = message->getParams().at(0);
		nonceSize = std::stoi(message->getParams().at(1));
		serverThread.sendMessage("{\"params\": [\"czekoladowyPaczek_1\", \"password\"], \"id\": 1, \"method\": \"mining.authorize\"}\n");
		break;
	case MESSAGE_TYPE::SET_DIFFICULTY:
		std::cout << "diff" << std::endl;
		difficulty = std::stoi(message->getParams().at(0));
		difficulty = 2;
		break;
	case MESSAGE_TYPE::NOTIFY:
		std::cout << "notify" << std::endl;
		std::cout << "size: " << nonceSize << "   extraNonce1: " << extraNonce1 << "    diff: " << difficulty << std::endl;
		for(int i = 0; i < message->getParams().size(); i++){
			std::cout << message->getParams().at(i) << std::endl;
		}
		break;
	default:
		std::cout << "deafult" << std::endl;
		break;
	}
}