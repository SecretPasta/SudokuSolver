#ifndef SUDOKUSOLVER_HEADER_H
#define SUDOKUSOLVER_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "Coord.h"
#include "Cell.h"

#define n 9

class SimpleTimer { // class for benchmarking
public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::cout << "Elapsed time:\t " << ((std::chrono::duration<double>)(end - start)).count() << " seconds";
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
sudokuVector Init(int grid[][n]);
void Solve(sudokuVector& grid);
void PrintGrid(sudokuVector& grid);
int CtoI(const char& x);

#endif //SUDOKUSOLVER_SRC_HEADER_H