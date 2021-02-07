#include <iostream>
#include "Vector.h"

int main() { 

	Vector a(10, 10, 10), b(1, 2, 3);

	std::cout << a - b << std::endl;

	return 0;
}