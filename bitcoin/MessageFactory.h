#pragma once

#include <string>

class MessageFactory
{
public:
	MessageFactory(void);
	~MessageFactory(void);
	
	static std::string getConnectMessage();
	static std::string getAuthMessage(std::string login, std::string pass);
	static std::string getSubmissionMessage(){};
	static std::string getDifficultyMessage(){};
};

