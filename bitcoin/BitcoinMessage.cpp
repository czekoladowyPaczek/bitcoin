#include "BitcoinMessage.h"
#include "jansson\jansson.h"
#include <fstream>
#include <iostream>

BitcoinMessage::BitcoinMessage(std::string message){
	msg = message;

	//decode json
	json_t* root;
	json_error_t error;
	root = json_loads(message.c_str(), message.length(), &error);
	json_t* sha = json_object_get(root, "sha");
	if(!json_is_object(sha)){
		std::cout << "nie istnieje" << std::endl;
	}
}

BitcoinMessage::~BitcoinMessage(void)
{
}

std::string BitcoinMessage::getMessage(){
	return msg;
}

std::vector<std::string> BitcoinMessage::getParams(){
	return params;
}

MESSAGE_TYPE BitcoinMessage::getType(){
	return type;
}
