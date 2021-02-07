#include <iostream>
#include "Vector.h"

int main() { 

	Vector
		a(3, 10, 7),
		b(8, -7, 4),
		c(2, 1, 0),
		d(-1, 2, 9),
		e(3, -4, 5);


	std::cout << (c.Dot(d)) << std::endl;
	std::cout << (d.Dot(c)) << std::endl;
	std::cout << "cannot" << std::endl;
	std::cout << (c.Cross(e).Dot(c)) << std::endl;
	std::cout << "cannot" << std::endl;
	std::cout << (a.Cross(b).Cross(c)) << std::endl;

	return 0;
}