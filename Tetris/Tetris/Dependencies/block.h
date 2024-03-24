#pragma once
#include <vector>
#include <map>
#include "colors.h"
#include "position.h" 
class Block
{
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
public:
	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int cols);
	std::vector<Position> GetCellPosition();
	void set_rotationState();
	void UndoRotation();
	
	int color_id;
	std::map<int, std::vector<Position>> cells;
	int rowOffset;
	int colOffset;
};