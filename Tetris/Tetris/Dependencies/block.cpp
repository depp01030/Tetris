#include "block.h" 
Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	colOffset = 0;
}
void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPosition();
	for (Position item : tiles) 
	{
		DrawRectangle(item.col * cellSize + offsetX, item.row * cellSize + offsetX , cellSize , cellSize , colors[color_id]);
	}
}
void Block::Move(int rows, int cols) {

	rowOffset += rows;
	colOffset += cols;
}
std::vector<Position> Block::GetCellPosition()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles) 
	{
		Position newPos = Position(item.row + rowOffset, item.col + colOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;

}
void Block::set_rotationState() {

	rotationState++;
	rotationState = rotationState % this->cells.size();

}
void Block::UndoRotation() {

	rotationState--;
	rotationState = rotationState % this->cells.size();

}