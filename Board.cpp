#include "StdAfx.h"
#include "Board.h"

Board::Board(void)
{
	setArray();
	flagMove = false;//flag check move
	flagDuplicates = false;// flag check Duplicates
}

Board::~Board(void)
{
}

/*initialize the array with 0*/
void Board::setArray()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			arrayBoard[i][j].setNumber(0);
		}
	}
}

void Board::setArrayByPosition(int i, int j)
{
	this->arrayBoard[i][j].setNumber(2);
}

/*function to move numbers to the top*/
void Board::swapTop(int j)/*input is the number of columns*/
{
	for(int i = 3; i >= 1; i--)
	{
		if(this->arrayBoard[i-1][j].getNumber() == 0)
		{
			if(this->arrayBoard[i][j].getNumber() != 0)
			{
				this->arrayBoard[i-1][j].setNumber(this->arrayBoard[i-1][j].getNumber() + this->arrayBoard[i][j].getNumber());
				this->arrayBoard[i][j].setNumber(0);
				this->flagMove = true;
			}
		}
		else
		{
			if(this->arrayBoard[i][j].getNumber() == this->arrayBoard[i-1][j].getNumber())
			{
				this->flagDuplicates = true;
			}
		}
	}
}

/*function to move numbers to the left*/
void Board::swapLeft(int i)/*input is the number of line*/
{
	for(int j = 3; j >= 1; j--)
	{
		if(this->arrayBoard[i][j-1].getNumber() == 0)
		{
			if(this->arrayBoard[i][j].getNumber() != 0)
			{
				this->arrayBoard[i][j-1].setNumber(this->arrayBoard[i][j-1].getNumber() + this->arrayBoard[i][j].getNumber());
				this->arrayBoard[i][j].setNumber(0);
				this->flagMove = true;
			}
		}
		else
		{
			if(this->arrayBoard[i][j-1].getNumber() == this->arrayBoard[i][j].getNumber())
			{
				this->flagDuplicates = true;
			}
		}
	}
}

/*function to move numbers to the right*/
void Board::swapRight(int i)/*input is the number of line*/
{
	for(int j = 0; j <= 2; j++)
	{
		if(this->arrayBoard[i][j+1].getNumber() == 0)
		{
			if(this->arrayBoard[i][j].getNumber() != 0)
			{
				this->arrayBoard[i][j+1].setNumber(this->arrayBoard[i][j+1].getNumber() + this->arrayBoard[i][j].getNumber());
				this->arrayBoard[i][j].setNumber(0);
				this->flagMove = true;
			}
		}
		else
		{
			if(this->arrayBoard[i][j+1].getNumber() == this->arrayBoard[i][j].getNumber())
			{
				this->flagDuplicates = true;
			}
		}
	}
}

/*function to move numbers to the bot*/
void Board::swapBot(int j)/*input is the number of columns*/
{
	for(int i = 0; i <= 2; i++)
	{
		if(this->arrayBoard[i+1][j].getNumber() == 0)
		{
			if(this->arrayBoard[i][j].getNumber() != 0)
			{
				this->arrayBoard[i+1][j].setNumber(this->arrayBoard[i+1][j].getNumber() + this->arrayBoard[i][j].getNumber());
				this->arrayBoard[i][j].setNumber(0);
				this->flagMove = true;
			}
		}
		else
		{
			if(this->arrayBoard[i+1][j].getNumber() == this->arrayBoard[i][j].getNumber())
			{
				this->flagDuplicates = true;
			}
		}
	}
}

/*function used to move*/
void Board::move(string input)
{
	if(input == "a" || input == "A")
	{
		for (int i = 0; i < 4; i++)
		{
			swapLeft(i);
			if(this->flagDuplicates == true)
			{
				swapLeft(i);
				this->flagDuplicates = false;
			}
			int j = 0;
			while(j < 4)
			{
				if(this->arrayBoard[i][j].getNumber() != 0 && this->arrayBoard[i][j].getNumber() == this->arrayBoard[i][j+1].getNumber())
				{
					this->arrayBoard[i][j].setNumber(this->arrayBoard[i][j].getNumber() + this->arrayBoard[i][j+1].getNumber());
					this->arrayBoard[i][j+1].setNumber(0);
					swapLeft(i);
					this->flagMove = true;
				}
				j++;
			}
		}
	}

	else if(input == "d" || input == "D"){
		for(int i = 0; i < 4; i++){
			swapRight(i);
			if(this->flagDuplicates == true){
				swapRight(i);
				this->flagDuplicates = false;
			}
			int j = 3;
			while(j >= 1){
				if(this->arrayBoard[i][j].getNumber() != 0 && this->arrayBoard[i][j].getNumber() == this->arrayBoard[i][j-1].getNumber()){
					this->arrayBoard[i][j].setNumber(this->arrayBoard[i][j].getNumber() + this->arrayBoard[i][j-1].getNumber());
					this->arrayBoard[i][j-1].setNumber(0);
					swapRight(i);
					this->flagMove = true;
				}
				j--;
			}
		}
	}

	else if(input == "w" || input == "W"){
		for(int j = 0; j < 4; j++){
			swapTop(j);
			if(this->flagDuplicates == true){
				swapTop(j);
				this->flagDuplicates = false;
			}
			int i = 0;
			while(i < 4){
				if(this->arrayBoard[i][j].getNumber() != 0 && this->arrayBoard[i][j].getNumber() == this->arrayBoard[i+1][j].getNumber()){
					this->arrayBoard[i][j].setNumber(this->arrayBoard[i][j].getNumber() + this->arrayBoard[i+1][j].getNumber());
					this->arrayBoard[i+1][j].setNumber(0);
					swapTop(i);
					this->flagMove = true;
				}
				i++;
			}
		}
	}

	else if(input == "s" || input == "S"){
		for(int j = 0; j < 4; j++){
			swapBot(j);
			if(this->flagDuplicates == true){
				swapBot(j);
				this->flagDuplicates = false;
			}
			int i= 3;
			while(i >= 1){
				if(this->arrayBoard[i][j].getNumber() != 0 && this->arrayBoard[i][j].getNumber() == this->arrayBoard[i-1][j].getNumber()){
					this->arrayBoard[i][j].setNumber(this->arrayBoard[i][j].getNumber() + this->arrayBoard[i-1][j].getNumber());
					this->arrayBoard[i-1][j].setNumber(0);
					swapBot(j);
					this->flagMove = true;
				}
				i--;
			}
		}
	}
}

void Board::show()
{
	int dem = 0;
	int line;
	int columns;
	string input;

	do 
	{
		if(dem == 0)
		{
			line = this->tile.randomLocation();
			columns = this->tile.randomLocation();
			this->setArrayByPosition(line,columns);
			dem++;
		}
		else if(dem == 1)
		{
			line = this->tile.randomLocation();
			columns = this->tile.randomLocation();
			while(this->arrayBoard[line][columns].getNumber() != 0)
			{
				line = this->tile.randomLocation();
				columns = this->tile.randomLocation();
			}
			this->setArrayByPosition(line,columns);
			dem++;
		}
		else
		{
			break;	
		}
	} while (true);

	do 
	{
		system("cls");
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				cout << this->arrayBoard[i][j];
				cout << " ";
			}
			cout << endl;
		}
		cout << "Nhap nut di chuyen (nhap exit de thoat): ";
		cin >> input;
		this->move(input);

		if(this->flagMove == true)
		{
			line = this->tile.randomLocation();
			columns = this->tile.randomLocation();
			while (this->arrayBoard[line][columns].getNumber() != 0)
			{
				line = this->tile.randomLocation();
				columns = this->tile.randomLocation();
			}
			this->setArrayByPosition(line,columns);
			this->flagMove = false;
		}
		if(input == "exit")
			break;
	} while (true);
}