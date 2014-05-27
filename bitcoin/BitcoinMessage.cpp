#include "BitcoinMessage.h"
#include "jansson\jansson.h"
#include <fstream>
BitcoinMessage::BitcoinMessage(char* buff, int size){
	msg = std::string(buff, size);

	std::fstream plik;
	plik.open("sdads.txt");
	plik << msg;
	plik.close();
}

BitcoinMessage::BitcoinMessage(std::string message){
	msg = message;
}

BitcoinMessage::~BitcoinMessage(void)
{
}
