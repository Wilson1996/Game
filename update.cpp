#include "config.h"

//��ʾ����
void show()										
{
	putimage(0, 0, &img_bk);	// ��ʾ����
	setcolor(GREEN);
	setfillcolor(YELLOW);
	fillcircle(food.x, food.y, CircleRad);

	SNAKE *temp;
	temp=HEAD;
	temp=temp->point;
	setcolor(YELLOW);
	setfillcolor(BLUE);
	fillcircle(HEAD->x, HEAD->y, CircleRad+1);
	setcolor(YELLOW);
	setfillcolor(GREEN);
	while(temp!=NULL)
	{
		fillcircle(temp->x, temp->y, CircleRad);
		temp=temp->point;
	}
	int delay_time=100-score/5*10;
	if(delay_time<=40)
		delay_time=40;
	Sleep(delay_time);

	temp=HEAD;
	temp=temp->point;
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(HEAD->x, HEAD->y, CircleRad+1);
	while(temp!=NULL)
	{
		fillcircle(temp->x, temp->y, CircleRad);
		temp=temp->point;
	}
}

//���û������޹صĸ���
void updateWithoutInput()	
{
	int diff_x,diff_y;
	diff_x=HEAD->x-food.x;
	diff_y=HEAD->y-food.y;
	if((abs(diff_x)<=2*CircleRad)&&(abs(diff_y)<=2*CircleRad))
	{
		if((direction==up&&diff_x==0)||(direction==down&&diff_x==0)
			||(direction==left&&diff_y==0)||(direction==right&&diff_y==0))
		{
			SNAKE *temp;
			temp=HEAD;
			HEAD=(SNAKE *)malloc(sizeof(SNAKE));
			HEAD->x=food.x;
			HEAD->y=food.y;
			HEAD->point=temp;
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(food.x, food.y, CircleRad);
			food=FoodCreate();
			score++;
			mciSendString("close jpmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open .\\Jump.mp3 alias jpmusic", NULL, 0, NULL); // �򿪳Ե�ʳ�������
            mciSendString("play jpmusic", NULL, 0, NULL); // ������һ��
		}
	}

	SNAKE *temp,*temp_n;
	int xy_status=0;		//�����ж�����û�����ཻ�������������(û�гɹ�)

	//�ж���û���ཻ����Ѱ����û����ͬλ�õĽڵ�
	temp=HEAD;
	while(temp->point!=NULL)
	{
		temp_n=temp->point;
		while(temp_n!=NULL)
		{
			if((temp->x==temp_n->x)&&(temp->y==temp_n->y))
			{
					xy_status=1;
					break;
			}
			temp_n=temp_n->point;
		}
		if(xy_status)
			break;
		temp=temp->point;
	}
	//�߽ڵ��ǰ��
	temp=HEAD;
	int temp_x_l,temp_y_l,temp_x_n,temp_y_n;
	temp_x_l=temp->x;
	temp_y_l=temp->y;
	while((temp->point)!=NULL)
	{
		temp_x_n=(temp->point)->x;
		temp_y_n=(temp->point)->y;
		(temp->point)->x=temp_x_l;
		(temp->point)->y=temp_y_l;
		temp_x_l=temp_x_n;
		temp_y_l=temp_y_n;
		temp=temp->point;
	}
	if((xy_status==1)||(HEAD->x<=0)||(HEAD->x>=WIDTH)||(HEAD->y<=0)||(HEAD->y>=HEIGHT))
		FailStatus=1;
	if(FailStatus)
	{
		gameOnStatus=0;
	}
	if(direction==up)
	{
		HEAD->y-=2*CircleRad;
	}
	if(direction==down)
	{
		HEAD->y+=2*CircleRad;
	}
	if(direction==left)
	{
		HEAD->x-=2*CircleRad;
	}
	if(direction==right)
	{
		HEAD->x+=2*CircleRad;
	}
}

//���û������йصĸ���
void updateWithInput()				
{
	char cmd;
	if(kbhit())
	{
		cmd=getch();
		if(cmd=='w'||cmd==0x48)
		{
			direction=up;
		}
		else if(cmd=='s'||cmd==0x50)
		{
			direction=down;
		}
		else if(cmd=='a'||cmd==0x4b)
		{
			direction=left;
		}
		else if(cmd=='d'||cmd==0x4d)
		{
			direction=right;
		}
		else if(cmd==27)
			gameOnStatus=0;
	}
}