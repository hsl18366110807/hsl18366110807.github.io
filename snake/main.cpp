# include <iostream>
# include <Windows.h>
# include <conio.h>
# include "snake.h"
using namespace std;
char ch;
int main()
{
	while (1)
	{
		snake sn1(10, 10, 9, 10, 8, 10);                //声明对象
		system("cls");           //清屏
								 //system("color 3B");      //背景和字体颜色调整
		make_frame();            //打印框架
		sn1.display();            //显示蛇
		show();                  //游戏开始
		sn1.creat_food();         //产生食物
		while (sn1.cheak())       //检查是否死亡
		{
			sn1.Rightmove();      //右移
			sn1.display();        //显示蛇身
			if (sn1.eat_food())   //检查是否吃到食物
			{
				sn1.creat_food(); //重新产生食物
				sn1.display();
			}
			Sleep(500);          //等待500Ms
		p:	if (_kbhit())                      //是否有按键
		{
			ch = _getch();
			if (ch == 97 || ch == 100)
				goto p;
			if (ch == 115 || ch == 119)
				break;
		}
		}
	pp:	switch (ch)            //有按键
	{
	case 119:              //上移的情况
	{
		while (sn1.cheak())
		{
			sn1.Upmove();
			sn1.display();
			sn1.showhead();
			if (sn1.eat_food())
			{
				sn1.creat_food();
				sn1.display();

			}
			Sleep(500);
		pw:	if (_kbhit())
		{
			ch = _getch();
			if (ch == 119 || ch == 115)
				goto pw;
			if (ch == 97 || ch == 100)
				goto pp;
		}
		}
	}break;
	case 97:               //左移的情况
	{
		while (sn1.cheak())
		{
			sn1.Leftmove();
			sn1.display();
			sn1.showhead();
			if (sn1.eat_food())
			{
				sn1.creat_food();
				sn1.display();
			}
			Sleep(500);
		pa: if (_kbhit())
		{
			ch = _getch();
			if (ch == 97 || ch == 100)
				goto pa;
			if (ch == 115 || ch == 119)
				goto pp;
		}
		}
	}break;
	case 115:                //下移的情况
	{
		while (sn1.cheak())
		{
			sn1.Downmove();
			sn1.display();
			sn1.showhead();
			if (sn1.eat_food())
			{
				sn1.creat_food();
				sn1.display();

			}
			Sleep(500);
		ps:	if (_kbhit())
		{
			ch = _getch();
			if (ch == 115 || ch == 119)
				goto ps;
			if (ch == 97 || ch == 100)
				goto pp;
		}
		}
	}break;
	case 100:                   //右移的情况
	{
		while (sn1.cheak())
		{
			sn1.Rightmove();
			sn1.display();
			sn1.showhead();
			if (sn1.eat_food())
			{
				sn1.creat_food();
				sn1.display();
			}
			Sleep(500);
		pd:	if (_kbhit())
		{
			ch = _getch();
			if (ch == 100 || ch == 97)
				goto pd;
			if (ch == 119 || ch == 115)
				goto pp;
		}
		}
	}break;
	default:
		break;
	}
		gameover();            //显示游戏结束，是否重玩
	py:	ch = _getch();
		if (ch == 110)         //否
		{
			system("cls");
			break;
		}
		else if (ch == 121)   //是
			continue;
		else
			goto py;
	}
	return 0;
}