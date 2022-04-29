#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Tile.h"
using namespace std;

class Board
{
public:
	Board(void);
	~Board(void);
	void setArray();
	void move(string input);
	void swapTop(int j);
	void swapLeft(int i);
	void swapRight(int i);
	void swapBot(int j);
	void setArrayByPosition(int i, int j);
	void show();

private:
	int ArrayBoard[4][4];
	bool flagDuplicates;
	bool flagMove;
	Tile tile;
};
