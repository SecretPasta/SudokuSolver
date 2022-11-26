#pragma once

#include <iostream>
#include<vector>

#define n 9

typedef std::vector<cell> sudokuRow;
typedef std::vector<sudokuRow> sudokuVector;

struct coord {
	int x, y;
	coord(int x, int y) {}

	bool operator!=(const coord& other) const {
		return x != other.x || y != other.y;
	}

};
class cell {
	coord x; //coordinates of the cell;
	int num; // value of the cell
	bool safe = false; //a safe values are the original values of the grid to not be edited
	cell* back = nullptr; //pointer to the previous cell for backtracking
public:
	cell(coord x, int num, cell* back) :x(x), num(num), back(back) {
		if (!num)
			safe = true;
	}
	
	cell():x(coord(0,0)),num(0),back(nullptr) {}
	
	coord GetLocation() {
		return x;
	}

	int GetNum() {
		return num;
	}
	bool IsSafe() {
		return safe;
	}
	cell* GoBack() {
		return back;
	}
	void Increment() {
		num++;
	}

	bool operator== (const cell& other) const {
		return other.num == num;
	}

	~cell() {}

};

bool CheckColumn(sudokuVector Grid, coord c);
bool CheckRow(sudokuVector Grid, coord c);
bool checkSubGrid(sudokuVector Grid, coord c);
sudokuVector init(int grid[][9]);