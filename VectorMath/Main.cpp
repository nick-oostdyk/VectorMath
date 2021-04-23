#include <iostream>
#include "Vector.h"

int main() {

	Vector a = {2, 0, -3}, b = { 1, 3, 6};

	std::cout << (a < b) << std::endl;

	return 0;
}