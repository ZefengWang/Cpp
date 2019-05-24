#include <iostream>

enum Response {No=0,Yes,Maybe};

int main()
{
	Response res = Maybe;
	std::cout << res << std::endl;
	return 0;
}
