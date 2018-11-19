#include "config.h"

FOOD FoodCreate(void)
{
	FOOD foods;
	foods.x=(rand()%(WIDTH/(2*CircleRad)))*2*CircleRad+CircleRad;
	foods.y=(rand()%(HEIGHT/(2*CircleRad)))*2*CircleRad+CircleRad;

	setcolor(GREEN);
	setfillcolor(YELLOW);
	fillcircle(foods.x, foods.y, CircleRad);
	return foods;
}

SNAKE * SnakeInit(int n)
{
	int i;
	SNAKE *head,*tail,*temp;
	tail=(SNAKE *)malloc(sizeof(SNAKE));
	tail->x=WIDTH/2+CircleRad;
	tail->y=HEIGHT/2+CircleRad;
	tail->point=NULL;
	for(i=0;i<n-1;i++)
	{
		head=(SNAKE *)malloc(sizeof(SNAKE));
		head->x=tail->x+2*CircleRad;
		head->y=tail->y;
		head->point=tail;
		tail=head;
	}
	return head;
}

SNAKE * SpaceFree(SNAKE * &head)
{
	SNAKE *temp;
	while(head!=NULL)
	{
		temp=head->point;
		free(head);
		head=temp;
	}
	return NULL;
}