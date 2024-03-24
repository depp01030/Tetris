#pragma once
#include <vector>
#include <raylib.h>
class Grid {
private:
	int m_numRows;
	int m_numCols;
	int m_cellSize;
	std::vector<Color> colors;
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
public:
	//Grid();
	Grid(int numRows, int numCols);
	int** grid;
	void Initialize();
	void Print();
	void Draw();
	bool IsCellOutside(int row, int col);
	bool IsCellEmpty(int row, int col);
	int ClearFullRows();
};
