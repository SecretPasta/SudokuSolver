#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>

#define n 9


struct Coord {
	int x, y;
	Coord(int x, int y): x(x),y(y){}

	bool operator!=(const Coord& other) const {
		return x != other.x || y != other.y;
	}
	const Coord& operator++(int) {
		Coord result = *this;
		y++;
		if (y >= n)
		{
			y = 0;
			x++;
		}
		return result;
	}

};
class Cell {
	Coord c; //coordinates of the cell;
	Coord Back; // Coordinates of the previous cell for backtracking
	int num; // value of the cell
	bool safe = false; //safe values are the original values of the grid to not be edited
public:

	Cell(Coord c, int num, Coord Back) :c(c), num(num), Back(Back) {
		if (num != 0)
			safe = true;
	}
	
	Cell():c(Coord(0,0)),num(0),Back(Coord(0,0)) {}
	
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

	bool Increment() {
		if (num == 9)
		{
			num = 0;
			return false;
		}
		num++;
		return true;
	}

	bool operator== (const Cell& other) const {
		return other.num == num;
	}


};

class SimpleTimer // class for benchmarking
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

typedef std::vector<Cell> sudokuRow;
typedef std::vector<sudokuRow> sudokuVector;

bool CheckColumn(sudokuVector& Grid, Coord& c);
bool CheckRow(sudokuVector& Grid, Coord& c);
bool CheckSubGrid(sudokuVector& Grid, Coord& c);
bool CheckConditions(sudokuVector& Grid, Coord& c);
sudokuVector init(int grid[][9]);
void solve(sudokuVector& grid);
void PrintGrid(sudokuVector& grid);