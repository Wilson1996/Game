#ifndef  __SNAKESTRUCT_H
#define __SNAKESTRUCT_H

typedef struct snake
{
	int x;
	int y;
	struct snake *point;
}SNAKE;

typedef struct
{
	int x;
	int y;
}FOOD;

typedef enum{up,down,left,right}DIRECTION;

FOOD FoodCreate(void);
SNAKE * SnakeInit(int n);
SNAKE * SpaceFree(SNAKE * &head);
#endif
