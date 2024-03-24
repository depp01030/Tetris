#include "grid.h"
#include <iostream>
#include <array>
#include <random>
#include "Colors.h"
#include "globalParameters.h"
/*
Grid::Grid() {
	m_numRows = 20;
	m_numCols = 10;
	m_cellSize = 30;
	Initialize();
	colors = GetCellColors();
}

*/
Grid::Grid(int numRows, int numCols) :m_numRows(numRows), m_numCols(numCols)
{
	m_cellSize = 30;
	Initialize();
	colors = GetCellColors();
}

void Grid::Initialize() 
{ 
	/*
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(0, 7);
	*/
	

	grid = new int* [m_numRows];
	for (int row = 0; row < m_numRows; row++)
	{
		grid[row] = new int[m_numCols];
		for (int col = 0; col < m_numCols; col++)
		{
			grid[row][col] = 0;
		}
	}
}
void Grid::Print() 
{
	for (int row = 0; row < m_numRows; row++)
	{
		for (int col = 0; col < m_numCols; col++)
		{
			std::cout << grid[row][col] << " ";
		}
		std::cout << std::endl;
	}
}


void Grid::Draw()
{
	for (int row = 0; row < m_numRows; row++)
	{
		for (int col = 0; col < m_numCols; col++)
		{
			int cellValue = grid[row][col];

			DrawRectangle(col * m_cellSize+ edge, row * m_cellSize+ edge, m_cellSize-1, m_cellSize-1, colors[cellValue]);
		}
	}
}
bool Grid::IsCellOutside(int row, int col)
{
	if (row >= 0 && row < m_numRows && col >= 0 && col < m_numCols)
	{
		return false;
	}
	return true;
}
bool Grid::IsCellEmpty(int row, int col)
{
	if (grid[row][col] == 0)
	{
		return true;
	}
	return false;
}
bool Grid::IsRowFull(int row)
{
	for (int col = 0; col < m_numCols; col++)
	{
		if (grid[row][col] == 0)
		{
			return false;
		}
	}
	return true;
}
void Grid::ClearRow(int row)
{
	for (int col = 0; col < m_numCols; col++)
	{
		
		grid[row][col] = 0; 
		
	}
}

void Grid::MoveRowDown(int row, int numRows) 
{
	for (int col = 0; col < m_numCols; col++)
	{
		grid[row + numRows][col] = grid[row][col];
		grid[row][col] = 0;

	}

}
int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = m_numRows - 1; row >= 0; row--) 
	{
		if (this->IsRowFull(row))
		{
			this->ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;
}