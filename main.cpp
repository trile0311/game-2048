#include "stdafx.h"
#include "header.h"

void main(){
	string s;
	game g;
	int dem = 0;
	int x1;//vi tri khi di chuyen
	int y1;
	int x;// vi tri khi moi bat dau game
	int y;
	g.setArray();
	do 
	{
		x = g.randomLocation();
		y = g.randomLocation();
		if(g.getArray(x,y) == 0){
			g.setArrayInput(x,y);
			dem++;
		}
		if(dem == 2)
			break;

	} while (true);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << g.getArray(i,j);
			cout << " ";
		}
		cout << endl;
	}
	do 
	{
		cout << "Nhap nut di chuyen (nhap exit de thoat): ";
		cin >> s;
		g.move(s);

		if(g.getFlag() == true){
			x1 = g.randomLocation();
			y1 = g.randomLocation();
			while (g.getArray(x1,y1) != 0){
				x1 = g.randomLocation();
				y1 = g.randomLocation();
			}
			g.setArrayInput(x1,y1);
			g.setFlag();
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				cout << g.getArray(i,j);
				cout << " ";
			}
			cout << endl;
		}
		if(s == "exit")
			break;
		
	} while (true);
	

	system("pause");
}