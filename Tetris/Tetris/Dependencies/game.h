#pragma once
#include "grid.h"
#include "blocks.cpp"



class Game
{
private:
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	void RotateBlock();
	void LockBlock();
	bool IsBlockOutside();
	bool IsBlockFits();
	std::vector<Block> GetAllBlocks();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	void MoveBlockLeft();
	void MoveBlockRight();
	Grid grid;
public:
	bool isPause;
	bool gameOver;
	int score;
	Game(int row, int col);
	void HandleInput();
	Block GetRandomBlock();
	//Handle
	void MoveBlockDown();
	void Draw();
	
};
