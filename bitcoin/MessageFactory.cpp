#include "MessageFactory.h"


MessageFactory::MessageFactory(void){
}


MessageFactory::~MessageFactory(void){
}

std::string MessageFactory::getConnectMessage(){
	return "{\"id\": 1, \"method\": \"mining.subscribe\", \"params\": []}\n";
}

std::string MessageFactory::getAuthMessage(std::string login, std::string pass){
	return "{\"params\": [\"" + login + ", " + pass + "], \"id\": 2, \"method\": \"mining.authorize\"}\n";
}