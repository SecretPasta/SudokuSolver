#include "Coord.h"

Coord::Coord(int x, int y) : x(x), y(y) {}

bool Coord::operator!=(const Coord& other) const {
	return x != other.x || y != other.y;
}

const Coord& Coord::operator++(int) {
	Coord result = *this;
	y++;
	if (y >= 9)
	{
		y = 0;
		x++;
	}
	return result;
}