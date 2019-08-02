# include <iostream>
# include <Windows.h>
# include <time.h>
# include "snake.h"
# define MaxLen 20
# define MaxWen 30
using namespace std;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ���
void gotoxy(HANDLE hOut, int x, int y)          //���λ�õĺ���
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void snake::display()                       //��ӡ����
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (i == length - 1)               //��ӡ��ͷ
		{
			gotoxy(hOut, s[i].x, s[i].y);
			cout << '&';
		}
		else                               //��ӡ����
		{
			gotoxy(hOut, s[i].x, s[i].y);
			cout << '*';
		}
	}
	gotoxy(hOut, 0, 22);
}
void snake::Rightmove()                  //����
{
	right = 1; up = down = left = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].x++;                        //��ͷx��������
	for (int i = length - 2; i >= 0; i--)     //������ͷ�������Ľ�㶼����������һ����������
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);            //�������ƶ������� ��*��
	cout << ' ';
}
void snake::Leftmove()               //����
{
	left = 1; right = up = down = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].x--;                        //ͬ��
	for (int i = length - 2; i >= 0; i--)
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);         //ͬ��
	cout << ' ';
}
void snake::Downmove()            //����
{
	down = 1; right = up = left = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].y++;                        //ͬ��
	for (int i = length - 2; i >= 0; i--)
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);         //ͬ��
	cout << ' ';
}
void snake::Upmove()              //����
{
	up = 1; down = right = left = 0;
	int x1, x2, y1, y2;
	x1 = x2 = s[length - 1].x;
	y1 = y2 = s[length - 1].y;
	s[length - 1].y--;                      //ͬ��
	for (int i = length - 2; i >= 0; i--)
	{
		x2 = s[i].x; y2 = s[i].y;
		s[i].x = x1; s[i].y = y1;
		x1 = x2; y1 = y2;
	}
	gotoxy(hOut, x2, y2);        //ͬ��
	cout << ' ';
}
int snake::cheak()
{
	int flag = 0;
	for (int i = length - 2; i >= 0; i--)         //�Ƿ�ײ������
	{
		if (s[i].x == s[length - 1].x && s[i].y == s[length - 1].y)
		{
			flag = 1;     //�ǣ���ʶ��Ϊ1
			break;
		}
	}
	if (flag == 1 || (s[length - 1].x >= 30 + 1 || s[length - 1].x < 4) || (s[length - 1].y <= 1 || s[length - 1].y >= 20))
	{
		return 0;         //����Ƿ�ײ��������ײǽ
	}
	else
	{
		return 1;
	}
}
void snake::creat_food()          //����ʳ������
{
xy:	x3 = (rand() % (25)) + 3;
	y3 = (rand() % (17)) + 2;
	for (int i = length - 1; i >= 0; i--)   //���ʳ���Ƿ���������
	{
		if (s[i].x == x3 && s[i].y == y3)    //�Ǿ����²���ʳ������
			goto xy;
	}
	gotoxy(hOut, x3, y3);       //��ʾʳ��
	cout << '*';
}
int snake::eat_food()
{
	if (s[length - 1].x == x3 && s[length - 1].y == y3)   //��ͷ����ʳ��
	{
		if (up == 1)                    //������������ƣ�����һ����㣬Ϊ��ͷ����һ�����
		{
			s[length].x = x3;
			s[length].y = y3 - 1;
		}
		else if (down == 1)             //ͬ��
		{
			s[length].x = x3;
			s[length].y = y3 + 1;
		}
		else if (right == 1)            //ͬ��
		{
			s[length].x = x3 + 1;
			s[length].y = y3;
		}
		else if (left == 1)             //ͬ��
		{
			s[length].x = x3 - 1;
			s[length].y = y3;
		}
		length++;                       //�߳���1
		return 1;
	}
	else
		return 0;
}
void snake::showhead() {
	gotoxy(hOut, 35, 9);
	cout << '(' << s[length - 1].x << ',' << s[length - 1].y << ')';
	if (s[length - 1].y < 10) {
		gotoxy(hOut, 41, 9);
		cout << ' ';
	}
	gotoxy(hOut, 0, 22);
}
void make_frame()                      //��ӡ��ܺ���
{
	cout << "            ̰������Ϸ" << endl;
	gotoxy(hOut, 2, 1);
	cout << "�X";
	for (int i = 4; i < 2 + MaxWen; i++)
	{
		gotoxy(hOut, i, 1);
		printf("=");
	}
	for (int i = 2; i < MaxLen; i++)
	{
		gotoxy(hOut, 2, i);
		printf("�U");
	}
	gotoxy(hOut, 2 + MaxWen, 1);
	printf("�[");
	for (int i = 2; i < MaxLen; i++)
	{
		gotoxy(hOut, 2 + MaxWen, i);
		printf("�U");
	}
	gotoxy(hOut, 2, MaxLen);
	printf("�^");
	gotoxy(hOut, 2 + MaxWen, MaxLen);
	printf("�a");
	for (int i = 4; i < 2 + MaxWen; i++)
	{
		gotoxy(hOut, i, MaxLen);
		printf("=");
	}
}
void show()                //��ʾ������������Ϸ��ʼ����ʱ
{
	gotoxy(hOut, 35, 5);
	cout << "��:" << 'w';
	gotoxy(hOut, 35, 6);
	cout << "��:" << 'a';
	gotoxy(hOut, 35, 7);
	cout << "��:" << 's';
	gotoxy(hOut, 35, 8);
	cout << "��:" << 'd';
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
void gameover()              //��Ϸ��������
{
	system("cls");
	system("color 3B");
	gotoxy(hOut, 14, 5);
	cout << "       GAME OVER!";
	gotoxy(hOut, 14, 6);
	cout << "PLAY AGAIN ? Y(yes) \ N(no)";
}