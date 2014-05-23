#include "BitcoinMessage.h"


BitcoinMessage::BitcoinMessage(char* buff, int size){
	msg = std::string(buff, size);
}


BitcoinMessage::~BitcoinMessage(void)
{
}
