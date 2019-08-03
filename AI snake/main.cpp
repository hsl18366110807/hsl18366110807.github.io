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
		snake sn1(10,10,9,10,8,10,7,10,6,10,5,10);                //声明对象
		system("cls");           //清屏
		//system("color 3B");      //背景和字体颜色调整
		make_frame();            //打印框架
		sn1.display();            //显示蛇
		show();                  //游戏开始
		sn1.creat_food();         //产生食物
		while (sn1.cheak())       //检查是否死亡
		{
			if (sn1.getstate() == "right") {
			rp:	int dir = rand() % 3;
				switch (dir) {
				case 0:
					if (sn1.preCheakUpmove()) {
						sn1.Upmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto rp;
					break;
				case 1:
					if (sn1.preCheakDownmove()) {
						sn1.Downmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto rp;
					break;
				case 2:
					if (sn1.preCheakRightmove()) {
						sn1.Rightmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto rp;
					break;
				default: break;
				}
			}
			if (sn1.getstate() == "left") {
			lp:	int dir = rand() % 3;
				switch (dir) {
				case 0:
					if (sn1.preCheakUpmove()) {
						sn1.Upmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto lp;
					break;
				case 1:
					if (sn1.preCheakDownmove()) {
						sn1.Downmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto lp;
					break;
				case 2:
					if (sn1.preCheakLeftmove()) {
						sn1.Leftmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto lp;
					break;
				default: break;
				}
			}
	      	if (sn1.getstate() == "up")
			{
			up:	int dir = rand() % 3;
				switch (dir) {
				case 0:
					if (sn1.preCheakRightmove()) {
						sn1.Rightmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto up;
					break;
				case 1:
					if (sn1.preCheakLeftmove()) {
						sn1.Leftmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto up;
					break;
				case 2:
					if (sn1.preCheakUpmove()) {
						sn1.Upmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto up;
					break;
				default: break;
				}
			}
			if (sn1.getstate() == "down")
			{
		dp:	int dir = rand() % 3;
				switch (dir) {
				case 0:
					if (sn1.preCheakRightmove()) {
						sn1.Rightmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto dp;
					break;
				case 1:
					if (sn1.preCheakLeftmove()) {
						sn1.Leftmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto dp;
					break;
				case 2:
					if (sn1.preCheakDownmove()) {
						sn1.Downmove();
						sn1.display();
						sn1.showhead();
						if (sn1.eat_food())
						{
							sn1.creat_food();
							sn1.display();
							sn1.showhead();
						}
						Sleep(500);
					}
					else
						goto dp;
					break;
				default: break;
				}
			}
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
