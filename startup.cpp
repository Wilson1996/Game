#include "config.h"

//ȫ�ֱ�������
SNAKE *HEAD;
FOOD food;
DIRECTION direction;
IMAGE img_gameOver,img_bk,img_begin;		//ͼƬ����
int FailStatus;			//�����ж��Ƿ�ʧ��
int score;					//����
int gameOnStatus;//��Ϸ���еı�־
int exitStatus;			//��Ϸ�˳��ı�־

void startup(void)
{
	initgraph(WIDTH,HEIGHT);
	loadimage(&img_gameOver, ".\\gameOver.jpg");
	loadimage(&img_bk, ".\\background.jpg");
	loadimage(&img_begin, ".\\begin.jpg");
	srand((unsigned int)time(NULL));

	putimage(0, 0, &img_begin);	// ��ʾ��ʼ����
	mciSendString("open .\\background.mp3 alias bkmusic", NULL, 0, NULL);//�򿪱�������
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // ѭ������

	MOUSEMSG msg;
	while(1)
	{
		msg=GetMouseMsg();
		if(msg.x>=280&&msg.x<=360&&msg.y>=280&&msg.y<=300)
		{
			settextcolor(RED);
			settextstyle(23,0, _T("����"));
			outtextxy(280, 280, "��ʼ��Ϸ");
		}
		if((msg.uMsg==WM_LBUTTONDOWN)&&msg.x>=280&&msg.x<=360&&msg.y>=280&&msg.y<=300)
		{
			/*settextcolor(RED);
			settextstyle(20,0, _T("����"));
			outtextxy(WIDTH*0.43, HEIGHT*0.20, "x��");
			char s[5];
			sprintf(s, "%d", msg.x);
			outtextxy(WIDTH*0.5, HEIGHT*0.20, s);
			outtextxy(WIDTH*0.43, HEIGHT*0.30, "y��");
			sprintf(s, "%d", msg.y);
			outtextxy(WIDTH*0.5, HEIGHT*0.30, s);*/            //��������ͼƬ�����ֵ�����
			break;
		}
	}

	HEAD=SnakeInit(LENTH);
	food=FoodCreate();
	direction=right;				//�����ʼ��Ϊ����
	FailStatus=0;
	gameOnStatus=1;
	exitStatus=0;
	score=0;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));	// ���ÿ���̨ API�����֮ǰ�������ڵ����а�����
}