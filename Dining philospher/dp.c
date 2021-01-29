#include<stdio.h>
#include<unistd.h>

void wait(int *s)
{
	if(*s<=0)
		return;
	*s--;
}

void signal(int *s)
{
	*s++;
}

void eat(int *a,int *b,int c)
{
	c=c%5;
	wait((a+c));
	wait((a+c+1));


	if((*(a+c)==1)&&(*(a+c+1)==1))
		printf("\nphilospher %d is eating......",*(b+c));
	else
		printf("\nphilospher %d is waiting......",*(b+c));




}

void think(int *a,int *b,int c)
{
	c=c%5;

	signal((a+c));
	signal((a+c+1));
	printf("\nphilospher %d is thinking.....",*(b+c));

}

int main()
{
	int mutex[5]={1,1,1,1,1};
	int philospher[5]={1,2,3,4,5};
	int order[5]={1,3,2,5,4};
	for(int i=0;i<5;i++)
	{
		eat(mutex,philospher,order[i]-1);
	}

	return 0;

}