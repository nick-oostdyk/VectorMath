#include "Vector.h"

#include <iostream>
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
	return this->is_2d
		? this->x * _other.x + this->y * _other.y
		: this->x * _other.x + this->y * _other.y + this->x * _other.x;
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
	return this->is_2d
		? std::sqrt(std::pow(x, 2) + std::pow(y, 2))
		: std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
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
	return std::acos(this->Dot(_other) / this->Mag() * _other.Mag());
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