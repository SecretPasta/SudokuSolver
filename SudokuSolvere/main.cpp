#include "Header.h"




bool CheckSubGrid(sudokuVector& Grid, Coord& c) {

	int xStart = (c.x / 3) * 3, yStart = (c.y / 3) * 3;
	for (int i = xStart; i < xStart + 3; i++) {
		for (int j = yStart; j < yStart + 3; j++) {
			if (Grid[c.x][c.y] == Grid[i][j] && c!=Coord(i,j) )
				return false;
		}
	}
	return true;
}

bool CheckRow(sudokuVector& Grid, Coord& c) {
	for (int i = 0; i < n; i++) {
		if (Grid[c.x][i] == Grid[c.x][c.y] && c!= Coord(c.x,i)) {
			return false;
		}
	}
	return true;
}


bool CheckColumn(sudokuVector& Grid, Coord& c) {
	for (int i = 0; i < n; i++) {
		if (Grid[i][c.y] == Grid[c.x][c.y] && c!=Coord(i,c.y)) {
			return false;
		}
	}
	return true;
}



sudokuVector init(int grid[][9]) {

	sudokuVector result = sudokuVector();
	Coord back(0, 0);
	for (int i = 0; i < n; i++) {
		result.push_back(sudokuRow());
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				result[i].push_back(Cell(Coord(i, j), grid[i][j], back));
				back = Coord(i, j);
			}
			else
				result[i].push_back(Cell(Coord(i, j), grid[i][j], Coord(-1,-1)));
		}
	}
	return result;
}

bool CheckConditions(sudokuVector& Grid, Coord& c) {
	return CheckColumn(Grid, c) && CheckRow(Grid, c) && CheckSubGrid(Grid, c);
}

void solve(sudokuVector& grid) {
	for (Coord currentCoord(0, 0); currentCoord.x < n;)
	{
		if (grid[currentCoord.x][currentCoord.y].IsSafe())
		{
			currentCoord++;
			continue;
		}
		while (grid[currentCoord.x][currentCoord.y].Increment())
		{
			if (CheckConditions(grid, currentCoord))
				break;
		}
		if (!CheckConditions(grid, currentCoord))
		{
			currentCoord = grid[currentCoord.x][currentCoord.y].GoBack();
			continue;
		}
		currentCoord++;
	}

}

void PrintGrid(sudokuVector& grid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << grid[i][j].GetNum() << " ";
			if (j % 3 == 2)
				std::cout << '|';
		}
		if (i % 3 == 2)
			std::cout << "\n---------------------\n";
		else
			std::cout << "\n";
	}
}

int main() {
	std::string myString;
	std::ifstream Read1;
	Read1.open("Grids.txt");
	if (!Read1.is_open()) {
		exit(1);
	}

	// Reading from file-------------------------- Work in Progress
	char line[10];
	Read1 >> line;
	while (Read1.good()) {
		std::cout << line << "\n";
		Read1 >> line;
	}
	//----------------------------------------------
	int InputArray[n][n] = { 
		{0,0,3,0,2,0,6,0,0},
		{9,0,0,3,0,5,0,0,1},
		{0,0,1,8,0,6,4,0,0},
		{0,0,8,1,0,2,9,0,0},
		{7,0,0,0,0,0,0,0,8},
		{0,0,6,7,0,8,2,0,0},
		{0,0,2,6,0,9,5,0,0},
		{8,0,0,2,0,3,0,0,9},
		{0,0,5,0,1,0,3,0,0} };
	sudokuVector Grid = init(InputArray);
//	std::cout << "Inital Array:\n";
//	PrintGrid(Grid);
	{
		SimpleTimer simpleTimer;
		solve(Grid);
	}
//	std::cout << "\nSolved Array:\n";
//	PrintGrid(Grid);
}