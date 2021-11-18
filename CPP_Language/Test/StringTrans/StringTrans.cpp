#include "StringTrans.hpp"




std::vector<int> StringTrans::fn_string_to_int(std::string msg)
{
	std::vector<int> temp_data;
	int i = 0;
	while (i < msg.size()) {
		char c_temp = msg.at(i);
		temp_data.push_back((int)c_temp);
		i++;
	}
	return temp_data;
}

std::string StringTrans::fn_int_to_hex(std::vector<int> msg)
{
	std::stringstream* st;
	std::string result;
	int i = 0;
	while (i < msg.size()) {
		st = new std::stringstream();
		*st << "0x" << std::hex << msg[i];
		std::string temp = st->str();

		if (i == msg.size() - 1) {
			result += temp;
			break;
		}
		result += temp+"\\";
		delete st;
		i++;
	}
	return result;
}

void StringTrans::fn_run(std::string msg)
{
	std::vector<int> v_int_data;
	v_int_data=fn_string_to_int(msg);
	std::cout<<fn_int_to_hex(v_int_data)<<"\n";
}
