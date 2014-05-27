#pragma once

#include <string>

class BitcoinMessage
{
public:
	BitcoinMessage(char* buff, int size);
	BitcoinMessage(std::string messsage);
	~BitcoinMessage(void);

	std::string getMessage(){
		return msg;
	}
private:
	std::string msg;
};

