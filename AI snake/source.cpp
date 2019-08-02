
# include <iostream>
# include <Windows.h>
# include <time.h>
# include "snake.h"
# define MaxLen 20
# define MaxWen 30
using namespace std;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //获取句柄
void gotoxy(HANDLE hOut, int x, int y)          //输出位置的函数
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void snake::display()                       //打印蛇身
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (i == length - 1)               //打印蛇头
		{
			gotoxy(hOut, s[i].x, s[i].y);
			cout << '&';
		}
		else                               //打印蛇身
		{
			gotoxy(hOut, s[i].x, s[i].y);
			cout << '*';
		}
	}
	gotoxy(hOut, 0, 22);
}
void snake::Rightmove()                  //右移
{
	right = 1; up = down = left = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].x++;                        //蛇头x坐标自增
	for (int i = length - 2; i >= 0; i--)     //除了蛇头，其他的结点都等于它的上一个结点的坐标
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);            //消除蛇移动遗留的 ‘*’
	cout << ' ';
}
void snake::Leftmove()               //左移
{
	left = 1; right = up = down = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].x--;                        //同上
	for (int i = length - 2; i >= 0; i--)
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);         //同上
	cout << ' ';
}
void snake::Downmove()            //下移
{
	down = 1; right = up = left = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].y++;                        //同上
	for (int i = length - 2; i >= 0; i--)
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);         //同上
	cout << ' ';
}
void snake::Upmove()              //上移
{
	up = 1; down = right = left = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].y--;                      //同上
	for (int i = length - 2; i >= 0; i--)
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);        //同上
	cout << ' ';
}
int snake::cheak()
{
	int flag = 0;
	for (int i = length - 2; i >= 0; i--)         //是否撞到自身
	{
		if (s[i].x == s[length - 1].x && s[i].y == s[length - 1].y)
		{
			flag = 1;     //是，标识符为1
			break;
		}
	}
	if (flag == 1 || (s[length - 1].x >= 30 + 1 || s[length - 1].x < 4) || (s[length - 1].y <= 1 || s[length - 1].y >= 20))
	{
		return 0;         //检测是否撞自身，或者撞墙
	}
	else
	{
		return 1;
	}
}
int snake::preCheakRightmove()
{
	int x1 = s[length - 1].x + 1;
	int y1 = s[length - 1].y;
	int flag = 0;
	for (int i = length - 2; i >= 0; i--)         //是否撞到自身
	{
		if (s[i].x == x1 && s[i].y == y1)
		{
			flag = 1;     //是，标识符为1
			break;
		}
	}
	if (flag == 1 || (x1 >= 30 + 1 || x1 < 4) || (y1<= 1 || y1 >= 20))
	{
		return 0;         //检测是否撞自身，或者撞墙
	}
	else
	{
		return 1;
	}
}
int snake::preCheakLeftmove()
{
	int x1 = s[length - 1].x - 1;
	int y1 = s[length - 1].y;
	int flag = 0;
	for (int i = length - 2; i >= 0; i--)         //是否撞到自身
	{
		if (s[i].x == x1 && s[i].y == y1)
		{
			flag = 1;     //是，标识符为1
			break;
		}
	}
	if (flag == 1 || (x1 >= 30 + 1 || x1 < 4) || (y1 <= 1 || y1 >= 20))
	{
		return 0;         //检测是否撞自身，或者撞墙
	}
	else
	{
		return 1;
	}
}
int snake::preCheakDownmove()
{
	int x1 = s[length - 1].x;
	int y1 = s[length - 1].y + 1;
	int flag = 0;
	for (int i = length - 2; i >= 0; i--)         //是否撞到自身
	{
		if (s[i].x == x1 && s[i].y == y1)
		{
			flag = 1;     //是，标识符为1
			break;
		}
	}
	if (flag == 1 || (x1 >= 30 + 1 || x1 < 4) || (y1 <= 1 || y1 >= 20))
	{
		return 0;         //检测是否撞自身，或者撞墙
	}
	else
	{
		return 1;
	}
}
int snake::preCheakUpmove()
{
	int x1 = s[length - 1].x;
	int y1 = s[length - 1].y - 1;
	int flag = 0;
	for (int i = length - 2; i >= 0; i--)         //是否撞到自身
	{
		if (s[i].x == x1 && s[i].y == y1)
		{
			flag = 1;     //是，标识符为1
			break;
		}
	}
	if (flag == 1 || (x1 >= 30 + 1 || x1 < 4) || (y1 <= 1 || y1 >= 20))
	{
		return 0;         //检测是否撞自身，或者撞墙
	}
	else
	{
		return 1;
	}
}
void snake::creat_food()          //产生食物坐标
{
xy:	x3 = (rand() % (25)) + 3;
	y3 = (rand() % (17)) + 2;
	for (int i = length - 1; i >= 0; i--)   //检查食物是否在蛇身上
	{
		if (s[i].x == x3 && s[i].y == y3)    //是就重新产生食物坐标
			goto xy;
	}
	gotoxy(hOut, x3, y3);       //显示食物
	cout << '*';
}
string snake::getstate()
{
	string s;
	if (up == 1) {
		s = "up";
	}
	else if (down == 1) {
		s = "down";
	}
	else if (right == 1) {
		s = "right";
	}
	else if (left == 1) {
		s = "left";
	}
	return s;
}
int snake::eat_food()
{
	if (s[length - 1].x == x3 && s[length - 1].y == y3)   //蛇头碰到食物
	{
		if (up == 1)                    //如果蛇是在上移，增加一个结点，为蛇头的上一个结点
		{
			s[length].x = x3;
			s[length].y = y3 - 1;
		}
		else if (down == 1)             //同上
		{
			s[length].x = x3;
			s[length].y = y3 + 1;
		}
		else if (right == 1)            //同上
		{
			s[length].x = x3 + 1;
			s[length].y = y3;
		}
		else if (left == 1)             //同上
		{
			s[length].x = x3 - 1;
			s[length].y = y3;
		}
		length++;                       //蛇长加1
		return 1;
	}
	else
		return 0;
}
void snake::showhead() {
	gotoxy(hOut, 35, 9);
	cout <<'('<< s[length - 1].x <<','<< s[length - 1].y<<')';
	if (s[length - 1].y < 10) {
		gotoxy(hOut, 41, 9);
		cout << ' ';
	}
	gotoxy(hOut, 0, 22);
}
void make_frame()                      //打印框架函数
{
	cout << "            贪吃蛇游戏" << endl;
	gotoxy(hOut, 2, 1);
	cout << "╔";
	for (int i = 4; i < 2 + MaxWen; i++)
	{
		gotoxy(hOut, i, 1);
		printf("=");
	}
	for (int i = 2; i < MaxLen; i++)
	{
		gotoxy(hOut, 2, i);
		printf("║");
	}
	gotoxy(hOut, 2 + MaxWen, 1);
	printf("╗");
	for (int i = 2; i < MaxLen; i++)
	{
		gotoxy(hOut, 2 + MaxWen, i);
		printf("║");
	}
	gotoxy(hOut, 2, MaxLen);
	printf("╚");
	gotoxy(hOut, 2 + MaxWen, MaxLen);
	printf("╝");
	for (int i = 4; i < 2 + MaxWen; i++)
	{
		gotoxy(hOut, i, MaxLen);
		printf("=");
	}
}
void show()                //显示操作方法和游戏开始倒计时
{
	gotoxy(hOut, 35, 5);
	cout << "↑:" << 'w';
	gotoxy(hOut, 35, 6);
	cout << "←:" << 'a';
	gotoxy(hOut, 35, 7);
	cout << "↓:" << 's';
	gotoxy(hOut, 35, 8);
	cout << "→:" << 'd';
	gotoxy(hOut, 16, 5);
	cout << '3';
	Sleep(1000);
	gotoxy(hOut, 16, 5);
	cout << '2';
	Sleep(1000);
	gotoxy(hOut, 16, 5);
	cout << '1';
	Sleep(1000);
	gotoxy(hOut, 16, 5);
	cout << ' ';
}
void gameover()              //游戏结束函数
{
	system("cls");
	system("color 3B");
	gotoxy(hOut, 14, 5);
	cout << "       GAME OVER!";
	gotoxy(hOut, 14, 6);
	cout << "PLAY AGAIN ? Y(yes) \ N(no)";
}