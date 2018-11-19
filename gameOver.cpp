#include "config.h"

void gameOver()								//游戏结束相关处理
{
	HEAD=SpaceFree(HEAD);
	putimage(0, 0, &img_gameOver);	// 显示结束
	settextcolor(RED);
	settextstyle(20,0, _T("宋体"));
	outtextxy(WIDTH*0.43, HEIGHT*0.80, "得分：");
	char s[5];
	sprintf(s, "%d", score);
	outtextxy(WIDTH*0.51, HEIGHT*0.80, s);
	settextcolor(WHITE);
	settextstyle(25,0, _T("宋体"));
	outtextxy(WIDTH*0.25, HEIGHT*0.90, "继续");
	outtextxy(WIDTH*0.62, HEIGHT*0.90, "退出");
	mciSendString("close bkmusic", NULL, 0, NULL); // 把背景音乐关闭
	MOUSEMSG msg;
	while(1)
	{
		msg=GetMouseMsg();
		if(msg.uMsg==WM_LBUTTONDOWN)
		{
			if((msg.x>=160)&&(msg.x<=200)&&(msg.y>=430)&&(msg.y<=450))
			{
				break;
			}
			else if((msg.x>=400)&&(msg.x<=440)&&(msg.y>=430)&&(msg.y<=450))
			{
				exitStatus=1;
				closegraph();
				break;
			}
		}
	}
}
