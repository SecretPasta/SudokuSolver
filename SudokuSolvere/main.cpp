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

	for (int i = 0; i < n; i++) {
		result.push_back(sudokuRow());
		for (int j = 0; j < n; j++) {
			if (grid[i][j]) {
				result[i].push_back(cell(coord(i, j), grid[i][j], backptr));
				backptr = &result[i][j];
			}
			else
				result[i].push_back(cell(coord(i, j), grid[i][j], nullptr));
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
			if (grid[i.x][i.y].isSafe())
				break;

			do {
				grid[i.x][i.y].Increment();
			} while (!CheckConditions(grid,i) && grid[i.x][i.y].GetNum()!= 9);

			if (grid[i.x][i.y].GetNum() != 9)
				break;
			//grid[i.x][i.y].Increment();
			cell* back = grid[i.x][i.y].GoBack();
			i = back->GetLocation();
			break;


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


int main() {
	int InputArray[n][n];
	sudokuVector Grid = init(InputArray);

}