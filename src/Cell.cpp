#include "Cell.h"

Cell::Cell(Coord c, int num, Coord Back) :c(c), num(num), Back(Back) {
	if (num != 0)
		safe = true;
}

Cell::Cell() :c(Coord(0, 0)), num(0), Back(Coord(0, 0)) {}

bool Cell::Increment() {
	if (num == 9)
	{
		num = 0;
		return false;
	}
	num++;
	return true;
}
bool Cell::operator== (const Cell& other) const {
	return other.num == num;
}