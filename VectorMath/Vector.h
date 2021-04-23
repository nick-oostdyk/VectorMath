#pragma once
#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

class Vector {
	public:

	float x, y, z;
	bool is_2d;
	
	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float z);
	Vector(const Vector& _other);

	Vector Add(const Vector &_other) const;
	Vector Subtract(const Vector &_other) const;
	Vector Multiply(const float _val) const;
	Vector Divide(const float _val) const;
	float angleBetween(const Vector &_other) const;

	float Dot(const Vector &_other) const;
	Vector Cross(const Vector &_other) const;

	float Mag() const;
	Vector Normalized() const;

	Vector CartesianToPolar() const;
	Vector PolarToCartesian() const;

	Vector CartesianToSpherical() const;
	Vector SphericalToCartesian() const;
};

Vector operator+(const Vector &lhs, const Vector &rhs);
Vector operator-(const Vector &lhs, const Vector &rhs);
Vector operator*(const Vector &lhs, const float &rhs);
Vector operator/(const Vector &lhs, const float &rhs);
float operator<(const Vector &lhs, const Vector &rhs);
std::ostream &operator<<(std::ostream &os, const Vector &_vec);

#endif