/*
 * coordinate.cpp
 *
 *  Created on: Oct 21, 2026
 *      Author: Tangsang Chongbang
 */

#include "coordinate.h"
#include <cmath>
#include <iostream>


const float PI = std::acos(-1.0f);

Coordinate::Coordinate(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	std::cout << "Constructor generates objects at " << this << std::endl;
	std::cout << "(x, y, z) = (" << this->x << ", " << this->y << ", " << this->z << ")" <<std::endl;
}

Coordinate::~Coordinate() {
	std::cout << "Destructor destroys object at " << this << std::endl;
}


void Coordinate::setCartesian(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Coordinate::getCartesian(float &x, float &y, float &z) const {
	x = this->x;
	y = this->y;
	z = this->z;
}

void Coordinate::add(const Coordinate &c) {
	this->x += c.x;
	this->y += c.y;
	this->z += c.z;
}

void Coordinate::getCylinder(float &r, float &phi, float &h) const {
	r = std::hypot(this->x, this->y);

	if (this->x > 0) {
		phi = std::atan(y / x);
	}

	else if (this->x < 0 && this->y >= 0) {
		phi = std::atan(this->y / this->x) + PI;
	}

	else if (this->x < 0 && this->y < 0) {
		phi = std::atan(this->y / this->x) - PI;
	}

	else if (this->x == 0 && this->y > 0) {
		phi = PI / 2.0f;
	}

	else if (this->x == 0 && this->y < 0) {
		phi = -PI / 2.0f;
	}

	else {
		std::cout << "WARNING: phi is undefined at origin (x = 0, y = 0). Setting phi to 0." << std::endl;
		phi = 0.0f; /// <- Undefined origin case, x = 0, y = 0
	}

	phi *= (180.0f / PI);

	h = this->z;
}

void Coordinate::getPolar(float &r, float &phi, float &theta) const{
	r = std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2));

	if (this->x == 0.0f && this->y == 0.0f) {
		std::cout << "WARNING: phi is undefined at origin (x = 0, y = 0). Setting phi to 0." << std::endl;
		phi = 0.0f;
	}

	else if (this->y >= 0) {
		phi = std::acos(this->x / std::hypot(this->x, this->y));
	}

	else { // this->y < 0
		phi = 2 * PI - std::acos(this->x / std::hypot(this->x, this->y));
	}


	if (r == 0.0f) {
		std::cout << "WARNING: theta is undefined at the 3D origin (r=0). Setting theta to 0." << std::endl;
		theta = 0.0f;
	}
	else {
		theta = PI / 2.0f - std::atan(this->z / std::hypot(this->x , this->y));
	}


	phi *= (180.0f / PI);
	theta *= (180.0f / PI);
}

void Coordinate::print(coordinateType style) const{

	float r = 0.0f, phi = 0.0f, theta = 0.0f, h = 0.0f;
	switch (style) {

	case CARTESIAN:
		std::cout << "Cartesian representation (x, y, z) = " << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
		break;

	case POLAR:
		this->getPolar(r, phi, theta);
		std::cout << "Polar representation (r, phi, theta) = " << "(" << r << ", " << phi << ", " << theta << ")" << std::endl;
		break;

	case CYLINDER:
		this->getCylinder(r, phi, h);
		std::cout << "Cylinder representation (r, phi, z) = " << "(" << r << ", " << phi << ", " << h << ")" << std::endl;
		break;
	}
}
