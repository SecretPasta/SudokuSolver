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

sudokuVector Init(int grid[][n]) {

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

void Solve(sudokuVector& grid) {
	for (Coord currentCoord(0, 0); currentCoord.x < n;) {
		if (grid[currentCoord.x][currentCoord.y].IsSafe()) {
			currentCoord++;
			continue;
		}
		while (grid[currentCoord.x][currentCoord.y].Increment()) {
			if (CheckConditions(grid, currentCoord))
				break;
		}
		if (grid[currentCoord.x][currentCoord.y].GetNum() == 0) {
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

int CtoI(const char& x) {
	return x - '0';
}

int main() {
	std::ifstream file;
	std::string MyRow;
	int sum = 0;
	int total = 0;
	int Grids[50][n][n] = {};
	int s = 0;
	// Reading from file to create a Tensor of Grids-------
	file.open("Grids.txt");
	if (!file.is_open()) {
		exit(1);
	}
	while (file.good()) {
		file >> MyRow; //Skipping the Word "Grid"
		file >> MyRow; // Skipping the number of the Grid
		for (int i = 0; i < n; i++) {
			file >> MyRow;
			for (int j = 0; j < n; j++) {
				char z = MyRow[j];
				Grids[s][i][j] = CtoI(z);
			}
		}
		s++;
	}
	//----------------------------------------------------

	// Solving 50 Grids with a timer
	{
		SimpleTimer simpleTimer;
		for (int g = 0; g < 50; g++) {
			sudokuVector MyGrid = Init(Grids[g]);
			
			{
				SimpleTimer simpleTimer;
				//PrintGrid(MyGrid);
				Solve(MyGrid);
				//PrintGrid(MyGrid);
				sum = (MyGrid[0][0].GetNum()*100 + MyGrid[0][1].GetNum()*10 + MyGrid[0][2].GetNum());
				std::cout << "Grid Number " << g+1 << ":\t ";
			}
			std::cout << "\tSum is: " << sum << "\n"; //Sum of 3 numbers
			total += sum;
		}
		std::cout << "Total "; // Total Time Elapsed 
	}
	std::cout << "\tTotal is: " << total; // Total of first 3 digits
	
}