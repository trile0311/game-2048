#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>
using namespace std;

class game{
private:
	int number;
	int location;
	int a[4][4];
	bool flag;
	bool flagduplicates;/*co de xem 2 so ke nhau co khac 0 khong*/

public: 
	game(){
		number = 0;
		location = 0;
		flag = false;
		flagduplicates = false;
	}

	~game(){}

	void setNumber(int number){
		this->number = number;
	}

	int getNumber(){
		return this->number;
	}

	void setLocation(int location){
		this->location = location;
	}

	int getLocation(){
		return this->location;
	}

	void setArray(){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				a[i][j] = 0;
			}
		}
	}

	void setArrayInput(int x, int y){
		this->a[x][y] = 2;
	}

	int getArray(int i, int j){
		return this->a[i][j];
	}

	void setFlag(){
		this->flag = false;
	}

	bool getFlag(){
		return this->flag;
	}

	int randomLocation(){
		srand((int)time(0));
		int n = rand()% (4);
		return n;
	}
	void swapLeft(int i)/*truyen vao so dong*/{
		for(int j = 3; j >= 1; j--){
			if(this->a[i][j-1] == 0){
				if(this->a[i][j] != 0){
					this->a[i][j-1] = this->a[i][j-1] + this->a[i][j];
					this->a[i][j] = 0;
					this->flag = true;
				}
			}
			else{
				if(this->a[i][j-1] == this->a[i][j])
				{
					this->flagduplicates = true;
				}
			}
		}
	}
	
	void swapRight(int i){
		for(int j = 0; j <= 2; j++){
			if(this->a[i][j+1] == 0){
				if(this->a[i][j] != 0){
					this->a[i][j+1] = this->a[i][j+1] + this->a[i][j];
					this->a[i][j] = 0;
					this->flag = true;
				}
			}
			else{
				if(this->a[i][j+1] == this->a[i][j])
				{
					this->flagduplicates = true;
				}
			}
		}
	}

	void move(string input){
		if(input == "a" || input == "A"){
			for (int i = 0; i < 4; i++){
				swapLeft(i);
				if(this->flagduplicates == true){
					swapLeft(i);
					this->flagduplicates = false;
				}
				int j = 0;
				while(j < 4){
					if(this->a[i][j] != 0 && this->a[i][j] == this->a[i][j+1]){
						this->a[i][j] = this->a[i][j] + this->a[i][j+1];
						this->a[i][j+1] = 0;
						swapLeft(i);
						this->flag = true;
					}
					j++;
				}
			}
		}
		
		else if(input == "d" || input == "D"){
			for(int i = 0; i < 4; i++){
				swapRight(i);
				if(this->flagduplicates == true){
					swapRight(i);
					this->flagduplicates = false;
				}
				int j = 3;
				while(j >= 1){
					if(this->a[i][j] != 0 && this->a[i][j] == this->a[i][j-1]){
						this->a[i][j] = this->a[i][j] + this->a[i][j-1];
						this->a[i][j-1] = 0;
						swapLeft(i);
						this->flag = true;
					}
					j++;
				}
			}
		}

		else if(input == "w" || input == "W"){
			for(int i = 3; i >= 1; i--){
				for(int j = 3; j >= 0; j--){
					if(this->a[i-1][j] == 0){
						if(this->a[i][j] != 0){
							this->a[i-1][j] = this->a[i-1][j] + this->a[i][j];
							this->a[i][j] = 0;
							this->flag = true;
						}
					}
					else{
						if(this->a[i-1][j] == this->a[i][j]){
							this->a[i-1][j] = this->a[i-1][j] + this->a[i][j];
							this->a[i][j] = 0;
							this->flag = true;
						}
					}
				}
			}
		}

		else if(input == "s" || input == "S"){
			for(int i = 0; i <= 2; i++){
				for(int j = 0; j < 4; j++){
					if(this->a[i+1][j] == 0){
						if(this->a[i][j] != 0){
							this->a[i+1][j] = this->a[i+1][j] + this->a[i][j];
							this->a[i][j] = 0;
							this->flag = true;
						}
					}
					else{
						if(this->a[i+1][j] == this->a[i][j]){
							this->a[i+1][j] = this->a[i+1][j] + this->a[i][j];
							this->a[i][j] = 0;
							this->flag = true;
						}
					}
				}
			}
		}
	}

};