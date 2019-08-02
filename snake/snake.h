struct Snake
{
	int x, y;
};
class snake {
public:
	snake(int x2, int y2, int x1, int y1, int x0, int y0) {  //构造函数
		length = 3;
		s[2].x = x2;
		s[2].y = y2;
		s[1].x = x1;
		s[1].y = y1;
		s[0].x = x0;
		s[0].y = y0;
		up = right = left = down = 0;
	}
	~snake() {}
	void display();                                    //显示蛇
	void Rightmove();                                  //上下左右移动蛇
	void Leftmove();
	void Upmove();
	void Downmove();
	void showhead();
	int cheak();                                      //检查是否撞到墙或者自身
	void creat_food();                                //产生实物
	int eat_food();                                   //吃食物
private:
	struct Snake s[100];                              //定义蛇最长100
	int length;                                       //当前蛇的长度
	int x3, y3;                                       //食物坐标
	int up, down, right, left;                        //蛇的状态
};
void make_frame();                                    //打印框架的函数
void show();                                          //游戏开始倒数
void gameover();