#include "config.h"

//全局变量定义
SNAKE *HEAD;
FOOD food;
DIRECTION direction;
IMAGE img_gameOver,img_bk,img_begin;		//图片对象
int FailStatus;			//用来判定是否失败
int score;					//分数
int gameOnStatus;//游戏进行的标志
int exitStatus;			//游戏退出的标志

void startup(void)
{
	initgraph(WIDTH,HEIGHT);
	loadimage(&img_gameOver, ".\\gameOver.jpg");
	loadimage(&img_bk, ".\\background.jpg");
	loadimage(&img_begin, ".\\begin.jpg");
	srand((unsigned int)time(NULL));

	putimage(0, 0, &img_begin);	// 显示开始画面
	mciSendString("open .\\background.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // 循环播放

	MOUSEMSG msg;
	while(1)
	{
		msg=GetMouseMsg();
		if(msg.x>=280&&msg.x<=360&&msg.y>=280&&msg.y<=300)
		{
			settextcolor(RED);
			settextstyle(23,0, _T("宋体"));
			outtextxy(280, 280, "开始游戏");
		}
		if((msg.uMsg==WM_LBUTTONDOWN)&&msg.x>=280&&msg.x<=360&&msg.y>=280&&msg.y<=300)
		{
			/*settextcolor(RED);
			settextstyle(20,0, _T("宋体"));
			outtextxy(WIDTH*0.43, HEIGHT*0.20, "x：");
			char s[5];
			sprintf(s, "%d", msg.x);
			outtextxy(WIDTH*0.5, HEIGHT*0.20, s);
			outtextxy(WIDTH*0.43, HEIGHT*0.30, "y：");
			sprintf(s, "%d", msg.y);
			outtextxy(WIDTH*0.5, HEIGHT*0.30, s);*/            //用来测试图片中文字的坐标
			break;
		}
	}

	HEAD=SnakeInit(LENTH);
	food=FoodCreate();
	direction=right;				//方向初始化为朝右
	FailStatus=0;
	gameOnStatus=1;
	exitStatus=0;
	score=0;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));	// 调用控制台 API，清空之前缓冲区内的所有按键。
}