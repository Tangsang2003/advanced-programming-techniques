#include <iostream>
#include "coordinate.h"

using namespace std;

int main() {

	cout << "Constructur" << endl << "===========" << endl;
	Coordinate c1(4, 4, 2);
	Coordinate c2;
	Coordinate c3(-4);

	cout << "Printing" << endl << "========" << endl;
	c1.print(CARTESIAN);
	c1.print(CYLINDER);
	c2.print(CYLINDER);

	c1.print(POLAR);
	c2.print(POLAR);
	c3.print(POLAR);

	cout << "Adding" << endl << "======" << endl;
	c1.add(c3);
	c2.add(Coordinate(1, 2, 3));
	c1.print(CARTESIAN);
	c2.print(CARTESIAN);

	return 0;
}
