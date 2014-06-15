#include "BitcoinMessage.h"
#include "jansson\jansson.h"
#include <fstream>
#include <iostream>

BitcoinMessage::BitcoinMessage(std::string message){
	msg = message;
	type = DEFAULT;
	//decode json
	json_t* root;
	json_error_t error;
	root = json_loads(message.c_str(), message.length(), &error);
	json_t* result = json_object_get(root, "result");
	json_t* param;
	if(json_is_array(result)){
		param = json_array_get(result, 1);
		params.push_back(json_string_value(param));
		param = json_array_get(result, 2);
		params.push_back(std::to_string(json_integer_value(param)));
		type = CONNECTED;
	} else if(result == NULL){
		json_t* miningMethod = json_object_get(root, "method");
		if(miningMethod == NULL){
			return;
		}
		json_t* j_params = json_object_get(root, "params");
		std::string method = json_string_value(miningMethod);
		if(method == "mining.set_difficulty"){
			type = SET_DIFFICULTY;
			param = json_array_get(j_params, 0);
			params.push_back(std::to_string(json_integer_value(param)));
		} else if(method == "mining.notify"){
			type = NOTIFY;
			std::cout << "size: " << json_array_size(j_params) << std::endl;
			param = json_array_get(j_params, 0);
			params.push_back(json_string_value(param));
			param = json_array_get(j_params, 1);
			params.push_back(json_string_value(param));
			param = json_array_get(j_params, 2);
			params.push_back(json_string_value(param));
			param = json_array_get(j_params, 3);
			params.push_back(json_string_value(param));
			param = json_array_get(j_params, 5);// 4 is missing becouse it is array of blocks!!
			params.push_back(json_string_value(param));
			param = json_array_get(j_params, 6);
			params.push_back(json_string_value(param));
			param = json_array_get(j_params, 7);
			params.push_back(json_string_value(param));

			//params[0] = Job ID. This is included when miners submit a results so work can be matched with proper transactions.
			//params[1] = Hash of previous block. Used to build the header.
			//params[2] = Coinbase (part 1). The miner inserts ExtraNonce1 and ExtraNonce2 after this section of the coinbase.
			//params[3] = Coinbase (part 2). The miner appends this after the first part of the coinbase and the two ExtraNonce values.
			//params[4] = Bitcoin block version, used in the block header.
			//params[5] = nBit, the encoded network difficulty. Used in the block header.
			//params[6] = nTime, the current time. nTime rolling should be supported, but should not increase faster than actual time.
			
			// params[7] - params[params.size] = List of merkle branches. The coinbase transaction is hashed against the merkle branches to build the final merkle root.
			json_t* jarray = json_array_get(j_params, 4);
			for(int i = 0; i < json_array_size(jarray); i++){
				param = json_array_get(jarray, i);
				params.push_back(json_string_value(param));
			}
		}
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
