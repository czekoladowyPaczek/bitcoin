#pragma once

#include <string>

class BitcoinMessage
{
public:
	BitcoinMessage(char* buff, int size);
	~BitcoinMessage(void);

	std::string getMessage(){
		return msg;
	}
private:
	std::string msg;
};

