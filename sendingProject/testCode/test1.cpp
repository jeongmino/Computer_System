#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(void)
{
	std::ifstream infile("data.txt");
	std::string line;
	std::getline(infile, line, '\0');
	std::string::size_type idx = 0;
	int cnt = 0;
	while (1)
	{
		idx = line.find(EOF,idx);
		if (idx == std::string::npos)
			break;
		cnt++;
		idx++;
	}
	std::cout << "cnt : " << cnt << std::endl;
	return (0);
}
