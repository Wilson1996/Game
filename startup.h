#ifndef  __STARTUP_H
#define __STARTUP_H

#pragma comment(lib,"Winmm.lib")		//引用windows的多媒体API
//全局变量声明
extern SNAKE *HEAD;		//HEAD为一个全局指针变量
extern DIRECTION direction;	//方向
extern FOOD food;
extern IMAGE img_gameOver,img_bk,img_begin;
extern int FailStatus,score;
extern int gameOnStatus;	//游戏进行的标志
extern int exitStatus;			//游戏退出的标志

void startup(void);

#endif