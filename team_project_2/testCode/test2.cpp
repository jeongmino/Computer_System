#include <iostream>
#include <string>

int main(void)
{
	std::string str = "0123456789";
	std::string line;
	int idx = 4;
	line = str.substr(0, idx);
	std::cout << str.substr(0, idx) << std::endl;
	std::cout << line.length() << std::endl;
	line = str.substr(idx + 1, idx + 5);
	std::cout << line.length() << std::endl;
	
	return 0;
}
