#include "config.h"

int main()
{
	while(!exitStatus)
	{
		startup();										//��Ϸ��ʼ��
		while(gameOnStatus)
		{
			show();										//��ʾ����
			updateWithInput();			//���û������йصĸ���
			updateWithoutInput();		//���û������޹صĸ���
		}
		gameOver();								//��Ϸ������ش���
	}
	return 0;
}
