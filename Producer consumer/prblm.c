#include<stdio.h>

void wait(int *a)
{
	while(*a<=0) 
	{
		printf("\nWaiting.....");
		return;
	}

	*a--;	
}

void signal(int *a)
{
	*a++;
}

void producer(int *a,int *b,int *c)
{
	do{
		*b++;
		*c--;

		wait(c);
		wait(a);

		printf("\nProducer is producing.");

		signal(a);
		signal(b);

	}while(0);
}

void consumer(int *a,int *b,int *c)
{
	do{		

		printf("\nConsumer is consuming.");

		wait(b);
		wait(a);

		*b--;
		*c++;

		signal(a);
		signal(c);

	}while(0);
}

int main()
{
	int mutex=1,full=0,empty=10;
	int s=0,count;
	producer(&mutex,&full,&empty);
	consumer(&mutex,&full,&empty);
	return 0;
}