#include "Vector.h"

#include <cmath>

// Constructors
Vector::Vector()
	: x(0), y(0), z(0), is_2d(0) { }

Vector::Vector(int _x, int _y)
	: x(_x), y(_y), z(0), is_2d(1) { }

Vector::Vector(int _x, int _y, int _z)
	: x(_x), y(_y), z(_z), is_2d(0) { }

Vector::Vector(const Vector &_other)
	: x(_other.x), y(_other.y), z(_other.z), is_2d(_other.is_2d) { }

// Math funcs
Vector Vector::Add(const Vector &_other) const {
	Vector returnVec = *this;

	returnVec.x += _other.x;
	returnVec.y += _other.y;
	if (!returnVec.is_2d)
		returnVec.z += _other.z;

	return returnVec;
}

Vector Vector::Subtract(const Vector &_other) const {
	return this->Add(_other.Multiply(-1));
}

Vector Vector::Multiply(const float _val) const {
	Vector returnVec = *this;

	returnVec.x *= _val;
	returnVec.y *= _val;
	if (!returnVec.is_2d)
		returnVec.z *= _val;

	return returnVec;
}

Vector Vector::Divide(const float _val) const {
	return this->Multiply(1 / _val);
}

float Vector::Dot(const Vector &_other) const {
	float val = 0;

	val += this->x * _other.x;
	val += this->y * _other.y;
	if (!this->is_2d)
		val += this->z * _other.z;

	return val;
}

Vector Vector::Cross(const Vector &_other) const {
	Vector returnVec = Vector(0, 0, 0);

	if (this->is_2d || _other.is_2d) {
		std::cerr << "Cross multiplication only works on 3d vectors." << std::endl;
		return returnVec;
	}

	returnVec.x = this->y * _other.z - this->z * _other.y;
	returnVec.y = this->z * _other.x - this->x * _other.z;
	returnVec.z = this->x * _other.y - this->y * _other.x;

	return returnVec;
}

float Vector::Mag() const {
	float val = 0;

	val += std::pow(x, 2);
	val += std::pow(y, 2);
	if (!this->is_2d) val += std::pow(z, 2);

	return std::sqrt(val);
}

Vector Vector::Normalized() const {
	Vector returnVec = *this;

	returnVec.x /= returnVec.Mag();
	returnVec.y /= returnVec.Mag();
	if (!returnVec.is_2d)
		returnVec.x /= returnVec.Mag();

	return returnVec;
}

float Vector::angleBetween(const Vector &_other) const {
	float pi = std::atan(1) * 4;

	auto dot = this->Dot(_other);
	auto mag = this->Mag() * _other.Mag();

	return std::acos(dot / mag) * 180.0f / pi;
}

Vector Vector::CartesianToPolar() const { 

	if (is_2d) { 
		
		auto r = Mag();
		float theta;

		if (x == 0)			// x = 0
			theta = y == 0 ? 0 : y > 0 ? 90 : -90 ; 
		else if (x > 0)		// x > 0
			theta = std::atan(y/x);
		else				// x < 0
			theta = std::atan(y / x) + (y >= 0 ? 180 : -180);

		return Vector(r, theta);

	} else
		std::cout << "Use CartesianToSpherical for 3D vectors.\n";

	return Vector(-10000, -10000);
}

Vector Vector::PolarToCartesian() const { 

	if (is_2d) { 

		float pi = std::atan(1) * 4;

		float r = this->x;
		float theta = this->y;

		float x = r * std::cos(theta * pi/180);
		float y = r * std::sin(theta * pi/180);

		return Vector(x, y);

	} else
		std::cout << "Use SphericalToCartesian for 3D vectors\n";

	return Vector(-10000, -10000);
}

Vector Vector::CartesianToSpherical() const {
	
	if (!is_2d) { 
	
		float rho = Mag(), theta, phi;

		if (x == 0)			// x = 0
			theta = y == 0 ? 0 : y > 0 ? 90 : -90;
		else if (x > 0)		// x > 0
			theta = std::atan(y / x);
		else				// x < 0
			theta = std::atan(y / x) + (y >= 0 ? 180 : -180);

		phi = Vector(x, y).Mag() / z;

		return Vector(rho, theta, phi);

	} else
		std::cout << "Use CartesianToPolar for 2D vectors\n";

	return Vector(-10000, -10000, -10000);
}

Vector Vector::SphericalToCartesian() const {

	if (!is_2d) {

		float rho	= this->x;
		float theta	= this->y;
		float phi	= this->z;

		float x = rho * std::sin(phi) * std::cos(theta);
		float y = rho * std::sin(phi) * std::sin(theta);
		float z = rho * std::cos(phi);

		return Vector(x, y, z);

	} else
		std::cout << "Use PolarToCartesian for 2D vectors\n";

	return Vector(-10000, -10000, -10000);
}


Vector operator+(const Vector &lhs, const Vector &rhs) {
	return lhs.Add(rhs);
}

Vector operator-(const Vector &lhs, const Vector &rhs) {
	return lhs.Subtract(rhs);
}

Vector operator*(const Vector &lhs, const float &rhs) {
	return lhs.Multiply(rhs);
}

Vector operator/(const Vector &lhs, const float &rhs) {
	return lhs.Divide(rhs);
}

float operator<(const Vector &lhs, const Vector &rhs) {
	return lhs.angleBetween(rhs);
}

std::ostream &operator<<(std::ostream &os, const Vector &_vec) {

	os << "x: " << _vec.x << std::endl;
	os << "y: " << _vec.y << std::endl;
	if (!_vec.is_2d)
		os << "z: " << _vec.z << std::endl;

	return os;
}