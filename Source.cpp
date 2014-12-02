#include <iostream>
#include "Header.h"

using namespace std;



void main()
{
	connect4<int> myconnect4;
	int grid[6][7];
	myconnect4.init(grid);

	int player = 1;
	for (int i = 0; i<100; i++)
	{
		myconnect4.display(grid);
		myconnect4.turn(grid, player);
		myconnect4.winlose(grid, player);
		if (player == 1)
		{
			player = 2;
			
			
		}
		else
		{
			player = 1;
		}
	}

}
