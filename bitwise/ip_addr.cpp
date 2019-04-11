#include <iostream>
int main()
{
	uint32_t ip = 0xc0a8ffff;
	std::cout << ((ip >> 24) & 0xff)  << ".";
	std::cout << ((ip >> 16) & 0xff) << ".";;
	std::cout << ((ip >> 8) & 0xff) << ".";;
	std::cout << ((ip >> 0 ) & 0xff) ;

}
