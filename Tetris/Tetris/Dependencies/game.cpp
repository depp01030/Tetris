#include "game.h"
#include "project_utils.h"
#include "globalParameters.h"
#include <iostream>
Game::Game(int row, int col) : grid(row, col)
{ 
	Reset();
}

Block Game::GetRandomBlock()
{

	int randomIndex = getRandom() % blocks.size();
	  
	Block block = blocks[randomIndex];
	block.Move(0, 3);
	return block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { ZBlock(), JBlock(), LBlock(), OBlock(), SBlock(), IBlock(), TBlock() };
}

void Game::Draw()
{
	//draw grid
	grid.Draw();  
	//draw block
	currentBlock.Draw(edge, edge);
	nextBlock.Draw(NEXT_BLOCK_POS_X, NEXT_BLOCK_POS_Y);
}
void Game::HandleInput() {
	/*
	if (IsKeyDown(KEY_LEFT))
	{
		MoveBlockLeft();
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		MoveBlockRight();
	}
	else if (IsKeyDown(KEY_DOWN))
	{
		MoveBlockDown();
	}
	else if (IsKeyDown(KEY_UP))
	{
		RotateBlock();
	}

	*/
	int keyPressed = GetKeyPressed();
	if (this->gameOver && keyPressed != 0)
	{
		// restart game
		gameOver = false;
		this->Reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_UP:
		RotateBlock();
		break;
	case KEY_TAB:
		this-> isPause = !this->isPause;
		break;
	}

}
void Game::MoveBlockLeft()
{
	if (!this->gameOver)
	{
		currentBlock.Move(0, -1);
		if (IsBlockOutside() or !IsBlockFits())
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{	if (!this->gameOver)
	{
		currentBlock.Move(0, 1);
		if (IsBlockOutside() or !IsBlockFits())
		{
			currentBlock.Move(0, -1);
		}
	}	
}
void Game::MoveBlockDown()
{

	if (!this->gameOver)
	{
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || !IsBlockFits())
		{
			currentBlock.Move(-1, 0);
			this->LockBlock();
		}
	}
}
void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		this->grid.grid[item.row][item.col] = this -> currentBlock.color_id;
	}

	this -> currentBlock = this -> nextBlock;
	//if the new born block is not fit -> GameOver.
	if (!IsBlockFits())
	{
		this->gameOver = true;
	}
	this -> nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	UpdateScore(rowsCleared, 0);
}
void Game::RotateBlock()
{
	//std::cout << "cur pos" << currentBlock.rowOffset << std::endl;

	if (!this->gameOver)
	{
		currentBlock.set_rotationState();
		if (this->IsBlockOutside() || !this->IsBlockFits())
		{
			currentBlock.UndoRotation();
		}
	}

}
bool Game::IsBlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (!grid.IsCellEmpty(item.row, item.col))
		{
			return false;
		}
	}
	return true;
}
bool Game::IsBlockOutside() {

	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.col))
		{
			return true;
		}
	}
	return false;
}

void Game::Reset() 
{
	
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
	isPause = false;
	gameOver = false;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}
	score += moveDownPoints;
}