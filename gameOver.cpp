#include "config.h"

void gameOver()								//��Ϸ������ش���
{
	HEAD=SpaceFree(HEAD);
	putimage(0, 0, &img_gameOver);	// ��ʾ����
	settextcolor(RED);
	settextstyle(20,0, _T("����"));
	outtextxy(WIDTH*0.43, HEIGHT*0.80, "�÷֣�");
	char s[5];
	sprintf(s, "%d", score);
	outtextxy(WIDTH*0.51, HEIGHT*0.80, s);
	settextcolor(WHITE);
	settextstyle(25,0, _T("����"));
	outtextxy(WIDTH*0.25, HEIGHT*0.90, "����");
	outtextxy(WIDTH*0.62, HEIGHT*0.90, "�˳�");
	mciSendString("close bkmusic", NULL, 0, NULL); // �ѱ������ֹر�
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
