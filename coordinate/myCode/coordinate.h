/*
 * coordinate.h
 *
 *  Created on: Oct 21, 2026
 *      Author: Tangsang Chongbang
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

/**
 * @brief Provides the available coordinate system formats.
 */
enum coordinateType {
	CARTESIAN,
	CYLINDER,
	POLAR
};

/**
 * @brief Represents a class that stores three coordinate values.
 *
 * Provides methods to represent the stored coordinates in Cartesian, Polar or Cylindrical format.
 */
class Coordinate {
private:
	float x, y, z;

	/**
	 * @brief Converts stored Cartesian coordinates into polar coordinates.
	 *
	 * @param r     Reference to store the radial distance (distance from the origin).
	 * @param phi   Reference to store the azimuthal angle (in radians).
	 * @param theta Reference to store the polar angle (in radians).
	 */
	void getPolar(float &r, float &phi, float &theta) const;

	/**
	 * @brief Converts stored Cartesian coordinates into Cylindrical coordinates.
	 *
	 * @param r   Reference to store the radial distance from the z-axis.
	 * @param phi Reference to store the azimuthal angle (in radians).
	 * @param h   Reference to store the height along the z-axis.
	 */
	void getCylinder(float &r, float &phi, float &h) const;


public:
	/**
	 * @brief Constructs a Coordinate object.
	 *
	 * @param x The x-coordinate. Defaults to 0.
	 * @param y The y-coordinate. Defaults to 0.
	 * @param z The z-coordinate. Defaults to 0.
	 */
	Coordinate(float x = 0.0, float y = 0.0, float z = 0.0);

	/**
	 * @brief Sets attributes to the passed parameter values.
	 *
	 * @param x The value to be assigned to x-coordinate.
	 * @param y The value to be assigned to y-coordinate.
	 * @param z The value to be assigned to z-coordinate.
	 */
	void setCartesian(float x, float y, float z);

	/**
	 * @brief Returns the values of the attributes to the passed variables.
	 *
	 * @param &x Reference to the variable where x-coordinate is to be returned.
	 * @param &y Reference to the variable where y-coordinate is to be returned.
	 * @param &z Reference to the variable where z-coordinate is to be returned.
	 */
	void getCartesian(float &x, float &y, float &z) const;

	/**
	 * @brief Adds another coordinate object to the current coordinate.
	 *
	 * @param c Reference to another Coordinate object.
	 */
	void add(const Coordinate &c);

	/**
	 * @brief Prints the current coordinate object in the format specified.
	 *
	 * @param style Represents one of the style defined in the coordinateType enum.s
	 */
	void print(coordinateType style) const;
	~Coordinate();

};

#endif /* COORDINATE_H_ */
