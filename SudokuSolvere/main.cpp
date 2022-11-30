#include "Header.h"

bool CheckSubGrid(sudokuVector& Grid, coord& c) {

	int xStart = c.x/3, yStart = c.y/3;
	for (int i = xStart; i < xStart + 3; i++) {
		for (int j = yStart; j < yStart + 3; j++) {
			if (Grid[c.x][c.y] == Grid[i][j] && c!=coord(i,j) )
				return false;
		}
	}
	return true;
}

bool CheckRow(sudokuVector& Grid, coord& c) {
	for (int i = 0; i < n; i++) {
		if (Grid[c.x][i] == Grid[c.x][c.y] && c!= coord(c.x,i)) {
			return false;
		}
	}
	return true;
}


bool CheckColumn(sudokuVector& Grid, coord& c) {
	for (int i = 0; i < n; i++) {
		if (Grid[i][c.y] == Grid[c.x][c.y] && c!=coord(i,c.y)) {
			return false;
		}
	}
	return true;
}



sudokuVector init(int grid[][9]) {

	sudokuVector result = sudokuVector();
	cell* backptr = nullptr;
	coord back(0, 0);

	for (int i = 0; i < n; i++) {
		result.push_back(sudokuRow());
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				result[i].push_back(cell(coord(i, j), grid[i][j], back));
				backptr = &result[i][j];
				back = coord(i, j);
			}
			else
				result[i].push_back(cell(coord(i, j), grid[i][j], coord(-1,-1)));
		}
	}
	return result;
}

bool CheckConditions(sudokuVector& Grid, coord& c) {
	return CheckColumn(Grid, c) && CheckRow(Grid, c) && CheckSubGrid(Grid, c);
}

void solve(sudokuVector& grid) {
	coord i(0,0);
	for (; i.x < n; i.x++)
	{
		for (; i.y < n; i.y++) {
			std::cout << "(" << i.x << "," << i.y << ")\n";
			PrintGrid(grid);
			if (grid[i.x][i.y].IsSafe())
				continue;

			do {
				grid[i.x][i.y].Increment();
			} while (!CheckConditions(grid,i) && grid[i.x][i.y].GetNum()!= 9);

			if (CheckConditions(grid,i))
				continue;
			grid[i.x][i.y].Increment(); // Incrementing past 9 will reset the cell to 0
			//cell* back = grid[i.x][i.y].GoBack();
			i = grid[i.x][i.y].goBack();
			continue;


			/*
			grid[i.x][i.y].Increment();
			if (CheckConditions(grid, i))
				break;

			do {
				grid[i.x][i.y].Increment();
			} while (!CheckConditions(grid, i) && grid[i.x][i.y].GetNum() != 9);
				grid[i.x][i.y].Increment();*/
		}
	}

}

void PrintGrid(sudokuVector& grid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << grid[i][j].GetNum() << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	int InputArray[n][n] = { {0,0,3,0,2,0,6,0,0},{9,0,0,3,0,5,0,0,1},{0,0,1,8,0,6,4,0,0},{0,0,8,1,0,2,9,0,0},{7,0,0,0,0,0,0,0,8},{0,0,6,7,0,8,2,0,0},{0,0,2,6,0,9,5,0,0
}, {8,0,0,2,0,3,0,0,9},{0,0,5,0,1,0,3,0,0} };
	sudokuVector Grid = init(InputArray);
	std::cout << "Inital Array:\n";
	PrintGrid(Grid);
	solve(Grid);
	std::cout << "\nSolved Array:\n";
	PrintGrid(Grid);
}