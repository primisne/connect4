#include <iostream>

using namespace std;

template<class T>
class connect4 {
public: void init(T grid[6][7]);
		void display(T grid[6][7]);
		T my_random(T min, T max);
		T computer_move(T grid[6][7], T player);
		void turn(T grid[6][7], T player);
		T winlose(T grid[6][7], T player);
};

template<class T>
void connect4<T> ::init(T grid[6][7])
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			grid[i][j] = 0;
		}
	}

}
template<class T>
void connect4<T> ::display(T grid[6][7])
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			if (grid[i][j] == 0)
			{
				cout << " ";
			}
			else if (grid[i][j] == 1)
			{
				cout << 'X';
			}
			else
			{
				cout << 'O';
			}
			//cout << grid[i][j];
			if (j<7)
			{
				cout << " |";
			}


		}

		cout << endl;
		if (i<6){
			cout << "--+--+--+--+--+--+--+" << endl;
		}
	}
}

template<class T>
T connect4<T> ::my_random(T min, T max)
{
	return rand() % (max - min + 1) + min;
}

template<class T>
T connect4<T> ::computer_move(T grid[6][7], T player)
{
	bool test = false;
	for (int i = 0; i < 6; i++)
	for (int j = 0; j < 7; j++)
	{
		if (grid[i][j] == 1 && grid[i + 1][j] != 1)
		{
			if (grid[i][j] == 1 && grid[i][j + 1] != 2 && grid[i][j + 1] != 1)
			{
				if (grid[5][j + 1] == 0)
				{
					grid[5][j + 1] = 2;
					test = true;
				}
				else if (grid[4][j + 1] == 0)
				{
					grid[4][j + 1] = 2;
					test = true;
				}
				else if (grid[3][j + 1] == 0)
				{
					grid[3][j + 1] = 2;
					test = true;

				}
				else if (grid[2][j + 1] == 0)
				{
					grid[2][j + 1] = 2;
					test = true;
				}
				else if (grid[1][j + 1] == 0)
				{
					grid[1][j + 1] = 2;
					test = true;
				}
				else if (grid[0][j + 1] == 0)
				{
					grid[0][j + 1] = 2;
					test = true;
				}

			}

			if (!test)
			{


				int x = my_random(0, 6);
				if (x <= 6 && x >= 0)
				{
					if (grid[6][x] == 0)
					{
						grid[6][x] = player;
					}

					else if (grid[5][x] == 0)
					{
						grid[5][x] = player;
					}
					else if (grid[4][x] == 0)
					{
						grid[4][x] = player;
					}
					else if (grid[3][x] == 0)
					{
						grid[3][x] = player;
					}
					else if (grid[2][x] == 0)
					{
						grid[2][x] = player;
					}
					else if (grid[1][x] == 0)
					{
						grid[1][x] = player;
					}
					else if (grid[0][x] == 0)
					{
						grid[0][x] = player;
					}

					test = true;
				}

			}
		}
		else if (grid[i + 1][j] == 1 && grid[i + 2][j] == 1 && grid[i + 3][j] == 1)
		{
			grid[i][j] = 2;

			test = true;
		}







	}
	return 0;
}


template<class T>
void connect4<T> ::turn(T grid[6][7], T player)
{
	cout << "Please choose number 0-6 " << endl;
	cout << "Player " << player << "'s turn" << endl;
	if (player == 1)
	{
		int x;
		cin >> x;
		if (x <= 6 && x >= 0)
		{
			if (grid[6][x] == 0)
			{
				grid[6][x] = player;
			}

			else if (grid[5][x] == 0)
			{
				grid[5][x] = player;
			}
			else if (grid[4][x] == 0)
			{
				grid[4][x] = player;
			}
			else if (grid[3][x] == 0)
			{
				grid[3][x] = player;
			}
			else if (grid[2][x] == 0)
			{
				grid[2][x] = player;
			}
			else if (grid[1][x] == 0)
			{
				grid[1][x] = player;
			}
			else if (grid[0][x] == 0)
			{
				grid[0][x] = player;
			}
			else
			{
				cout << "Pick an empty cell! - MISS A GO!";
			}

		}
		else
		{
			cout << "That's not in the grid - MISS A GO!";
		}
	}
	else if (player == 2)
	{
		computer_move(grid, player);
	}

}
template<class T>
T connect4<T> ::winlose(T grid[6][7], T player)
{

	for (int i = 0; i<6; i++)
	for (int j = 0; j<7; j++)
	{   
		if (grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i + 2][j] == 1 && grid[i + 3][j] == 1)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" << "You" << "win" << "::/(> O <)/" << endl;
		}
		if (grid[i][j] == 2 && grid[i + 1][j] == 2 && grid[i + 2][j] == 2 && grid[i + 3][j] == 2)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" << "PC" << "win" << "::/(> O <)/" << endl;
		}
		
		if (grid[i][j] == 1 && grid[i][j + 1] == 1 && grid[i][j + 2] == 1 && grid[i][j + 3] == 1)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" << "You" << "win" << "::/(> O <)/" << endl;
		}
		if (grid[i][j] == 2 && grid[i][j + 1] == 2 && grid[i][j + 2] == 2 && grid[i][j + 3] == 2)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" << "PC" << "win" << "::/(> O <)/" << endl;
		}
	}
	for (int i = 5; i >= 0; i--)
	for (int j = 0; j <= 5; j++)
	{
		
		if (grid[i][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 2][j + 2] == 1 && grid[i - 3][j + 3] == 1)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" << "You" << "win" << "::/(> O <)/" << endl;
		}
		if (grid[i][j] == 2 && grid[i - 1][j + 1] == 2 && grid[i - 2][j + 2] == 2 && grid[i - 3][j + 3] == 2)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" <<  "PC" << "win" << "::/(> O <)/" << endl;
		}

		if (grid[i][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i - 2][j - 2] == 1 && grid[i - 3][j - 3] == 1)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" << "You" << "win" << "::/(> O <)/" << endl;
		}
		if (grid[i][j] == 2 && grid[i - 1][j - 1] == 2 && grid[i - 2][j - 2] == 2 && grid[i - 3][j - 3] == 2)
		{
			cout << "!!!!!!!!!STOP PLAYING!!!!!!!!::Player" <<  "PC" << "win" << "::/(> O <)/" << endl;
		}
	}

	return 0;

}
