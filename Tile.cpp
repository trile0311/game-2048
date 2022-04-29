#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(void)
{
}

Tile::~Tile(void)
{
}

int Tile::randomLocation()
{
	srand((int)time(0));
	int n = rand()% (4);
	return n;
}

void Tile::setNumber(int input)
{
	this->number = input;
}

int Tile::getNumber()
{
	return this->number;
}