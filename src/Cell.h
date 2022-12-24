#ifndef SUDOKUSOLVER_CELL_H
#define SUDOKUSOLVER_CELL_H
#include "Coord.h"

class Cell {
	Coord c; //coordinates of the cell;
	Coord Back; // Coordinates of the previous cell for backtracking
	int num; // value of the cell
	bool safe = false; //safe values are the original values of the grid to not be edited
public:

	Cell(Coord c, int num, Coord Back);

	Cell();

	Coord GetLocation() {
		return c;
	}

	int GetNum() {
		return num;
	}
	bool IsSafe() {
		return safe;
	}
	Coord GoBack() {
		return Back;
	}

	bool Increment();

	bool operator== (const Cell& other) const;
};

#endif