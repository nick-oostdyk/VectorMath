#include <iostream>
#include "Vector.h"

int main() { 

	Vector a(1, 5), b(-1, 10);

	std::cout << a.angleBetween(b) << std::endl;

	return 0;
}