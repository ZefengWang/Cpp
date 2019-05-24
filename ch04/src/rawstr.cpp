#include <iostream>
#include <string>

int main()
{
	//std::string str = UR"(你好，我是你爸爸，哈哈哈哈哈。\\\\n\t\d\\\\)";
	std::string str = R"(你好，我是你爸爸，哈哈哈哈哈。\\\\n\t\d\\\\)";
	std::cout << str << std::endl;
	return 0;
}
