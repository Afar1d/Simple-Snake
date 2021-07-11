/*  This game is developed by 
 ********" Ahmed M. farid "*********
  ASU - 2021
*/
#include<iostream>
#include<conio.h> // to get the two function of input
#include<windows.h>//functoin sleep
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;
bool gameOver;
const int width = 20;
const int hight = 20; // MAp dimension
int x, y;//snake position
int fruitX, fruitY, score;//position of the fruit
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };//Enumeration
eDirection dir; //
int tailX[100], tailY[100];
int ntail; //tail lenght
//function
void Setup();
void Draw();
void Input();
void Logic();
// defined under the main

int main()
{
	bool check =true;
	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(30);//to slow the game
		if (!gameOver)
			check = false;
	}
	if (check == false)
	{
		//system("cls");
		cout << endl;
		cout << "--------- GAME OVER ---------\n";

	}


}
void Setup()
{
	gameOver = false;
	x = width / 2;
	y = hight / 2;
	fruitX = rand() % width;
	fruitY = rand() % hight;
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 4; i++)//the serface
		cout << "=";
	cout << endl;

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "||";
			if (i == y && j == x)//snake head
				cout << "@";
			else if (i == fruitY && j == fruitX)//fruit position
				cout << "$";
			else 
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}

				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << "||";
		}
		cout << endl;

	}

	for (int i = 0; i < width + 4; i++)//the bottom
		cout << "=";
	cout << endl;
	cout << "SCORE : " << score;
}
void Input()
{
	if (_kbhit()) //that make sure the user hit a key
	{
		switch (_getch())//that function return what key pressed
		{
			// ADWS direction
		case'a':
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
			// FOR ARROWS
		case KEY_LEFT:
			dir = LEFT;
			break;
		case KEY_RIGHT:
			dir = RIGHT;
			break;
		case KEY_UP:
			dir = UP;
			break;
		case KEY_DOWN:
			dir = DOWN;
			break;
		case'x':  //when snake hit something
			gameOver = true;
			break;
		default:
			break;
		}
	}
}
void Logic()
{
	int prevx = tailX[0];
	int prevy = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	int prev2x, prev2y;
	for (int i = 1; i < ntail; i++)
	{
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevx;
		tailY[i] = prevy;
		prevx = prev2y;
		prevy = prev2y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x<0 || y>hight || y < 0)
		gameOver = true;
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		cout << endl;
		fruitX = rand() % width;
		fruitY = rand() % hight;
		ntail++;
	}
}