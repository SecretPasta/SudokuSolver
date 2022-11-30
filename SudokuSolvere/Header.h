#pragma once

#include <iostream>
#include<vector>

#define n 9


struct coord {
	int x, y;
	coord(int x, int y): x(x),y(y){}

	bool operator!=(const coord& other) const {
		return x != other.x || y != other.y;
	}

};
class cell {
	coord c; //coordinates of the cell;
	coord Back;
	int num; // value of the cell
	bool safe = false; //safe values are the original values of the grid to not be edited
	//cell* back = nullptr; //pointer to the previous cell for backtracking
public:
	/*cell(coord c, int num, cell* back) :c(c), num(num), back(back) {
		if (num != 0)
			safe = true;
	}*/

	cell(coord c, int num, coord Back) :c(c), num(num), Back(Back) {
		if (num != 0)
			safe = true;
	}
	
	cell():c(coord(0,0)),num(0),Back(coord(0,0)) {}
	
	coord GetLocation() {
		return c;
	}

	int GetNum() {
		return num;
	}
	bool IsSafe() {
		return safe;
	}
	coord goBack() {
		return Back;
	}
	/*cell* GoBack() {
		return back;
	}*/
	void Increment() {
		if (num == 9)
			num = 0;
		else
			num++;
	}

	bool operator== (const cell& other) const {
		return other.num == num;
	}

	~cell() {}

};

typedef std::vector<cell> sudokuRow;
typedef std::vector<sudokuRow> sudokuVector;

bool CheckColumn(sudokuVector& Grid, coord& c);
bool CheckRow(sudokuVector& Grid, coord& c);
bool CheckSubGrid(sudokuVector& Grid, coord& c);
bool CheckConditions(sudokuVector& Grid, coord& c);
sudokuVector init(int grid[][9]);
void solve(sudokuVector& grid);
void PrintGrid(sudokuVector& grid);