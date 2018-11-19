#include "config.h"

int main()
{
	while(!exitStatus)
	{
		startup();										//游戏初始化
		while(gameOnStatus)
		{
			show();										//显示画面
			updateWithInput();			//与用户输入有关的更新
			updateWithoutInput();		//与用户输入无关的更新
		}
		gameOver();								//游戏结束相关处理
	}
	return 0;
}
