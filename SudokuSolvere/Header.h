#pragma once

#define n 9

struct coord {
	int x, y;
	coord(int x, int y) {}
	coord();
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
	cell() {

	}
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

	bool operator== (const int& x) const {
		return num == x;
	}

};

bool CheckColumn(cell Grid[][n], coord x);
bool CheckRow(cell Grid[][n], coord x);
bool checkSubGrid(cell Grid[][n], coord x);
cell init(int grid[][n]);