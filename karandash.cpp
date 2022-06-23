#include "Date.h"


int main()
{
	Date d;
	Date b(22, 06, 2021);
	std::cout << d - b << "\n";
	std::cout << d - 366 << "\n";
}