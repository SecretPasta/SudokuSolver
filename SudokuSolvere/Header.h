#pragma once

#include <iostream>
#include <vector>
#include <chrono>

#define n 9


struct coord {
	int x, y;
	coord(int x, int y): x(x),y(y){}

	bool operator!=(const coord& other) const {
		return x != other.x || y != other.y;
	}
	const coord& operator++(int) {
		coord result = *this;
		y++;
		if (y >= n)
		{
			y = 0;
			x++;
		}
		return result;
	}

};
class cell {
	coord c; //coordinates of the cell;
	coord Back;
	int num; // value of the cell
	bool safe = false; //safe values are the original values of the grid to not be edited
public:

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

	bool Increment() {
		if (num == 9)
		{
			num = 0;
			return false;
		}
		num++;
		return true;
	}

	bool operator== (const cell& other) const {
		return other.num == num;
	}


};

class SimpleTimer
{
public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::cout << "\n\nElapsed time:\t " << ((std::chrono::duration<double>)(end - start)).count() << " seconds\n";
	}


private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
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