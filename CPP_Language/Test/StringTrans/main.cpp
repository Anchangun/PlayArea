#include"StringTrans.hpp"

int main() {
	StringTrans st;
	std::string temp;
	std::cin >> temp;
	st.fn_run(temp);
	std::cout << temp;
	return 0;
}

