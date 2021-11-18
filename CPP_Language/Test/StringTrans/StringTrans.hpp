#pragma once
#include<iostream>
#include<cstring>
#include<sstream>
#include <vector>
class StringTrans{
	private :
	
		std::vector<int> fn_string_to_int(std::string msg);
		std::string fn_int_to_hex(std::vector<int> msg);
	public :
		void fn_run(std::string msg);
};

