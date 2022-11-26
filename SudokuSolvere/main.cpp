#include <iostream>
#include "Header.h"

bool checkSubGrid(cell Grid[][n], coord x) {
	for(int i = 0;i<3;i++)
		for (int j = 0; j < 3; j++) {

		}
	return true;
}

bool CheckRow(cell Grid[][n], coord x) {
	for (int i = 0; i < n; i++) {
		if (Grid[i][x.y].GetNum() == Grid[x.x][x.y].GetNum() && i != x.x) {
			return false;
		}
	}
	return true;
}


bool CheckColumn(cell Grid[][n], coord x) {
	for (int i = 0; i < n; i++) {
		if (Grid[x.x][i].GetNum() == Grid[x.x][x.y].GetNum() && i!=x.y) {
			return false;
		}
	}
	return true;
}



cell init(int grid[][9]) {
	cell Grid[n][n];
	cell* backptr = nullptr;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j]) {
				Grid[n][n] = cell(coord(i,j), grid[i][j], backptr);
				backptr = &Grid[i][j];
			}
			else
				Grid[n][n] = cell(coord(i, j), grid[i][j], nullptr);
		}
	}
	return Grid[n][n];
}





int main() {
	int InputArray[n][n];
	cell Grid = init(InputArray);

}