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
		snake sn1(10, 10, 9, 10, 8, 10);                //��������
		system("cls");           //����
								 //system("color 3B");      //������������ɫ����
		make_frame();            //��ӡ���
		sn1.display();            //��ʾ��
		show();                  //��Ϸ��ʼ
		sn1.creat_food();         //����ʳ��
		while (sn1.cheak())       //����Ƿ�����
		{
			sn1.Rightmove();      //����
			sn1.display();        //��ʾ����
			if (sn1.eat_food())   //����Ƿ�Ե�ʳ��
			{
				sn1.creat_food(); //���²���ʳ��
				sn1.display();
			}
			Sleep(500);          //�ȴ�500Ms
		p:	if (_kbhit())                      //�Ƿ��а���
		{
			ch = _getch();
			if (ch == 97 || ch == 100)
				goto p;
			if (ch == 115 || ch == 119)
				break;
		}
		}
	pp:	switch (ch)            //�а���
	{
	case 119:              //���Ƶ����
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
	case 97:               //���Ƶ����
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
	case 115:                //���Ƶ����
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
	case 100:                   //���Ƶ����
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
		gameover();            //��ʾ��Ϸ�������Ƿ�����
	py:	ch = _getch();
		if (ch == 110)         //��
		{
			system("cls");
			break;
		}
		else if (ch == 121)   //��
			continue;
		else
			goto py;
	}
	return 0;
}