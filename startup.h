#ifndef  __STARTUP_H
#define __STARTUP_H

#pragma comment(lib,"Winmm.lib")		//����windows�Ķ�ý��API
//ȫ�ֱ�������
extern SNAKE *HEAD;		//HEADΪһ��ȫ��ָ�����
extern DIRECTION direction;	//����
extern FOOD food;
extern IMAGE img_gameOver,img_bk,img_begin;
extern int FailStatus,score;
extern int gameOnStatus;	//��Ϸ���еı�־
extern int exitStatus;			//��Ϸ�˳��ı�־

void startup(void);

#endif