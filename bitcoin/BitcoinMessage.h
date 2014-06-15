#pragma once

#include <string>
#include <vector>

enum MESSAGE_TYPE{
	CONNECTED = 0,
	SUBSCRIBED = 1,
	SET_DIFFICULTY = 2,
	NOTIFY = 3,
	DEFAULT = 4
};


class BitcoinMessage
{
public:
	BitcoinMessage(std::string message);
	~BitcoinMessage(void);

	std::string getMessage();
	MESSAGE_TYPE getType();
	std::vector<std::string> getParams();
private:
	std::string msg;
	MESSAGE_TYPE type;
	std::vector<std::string> params;
};

