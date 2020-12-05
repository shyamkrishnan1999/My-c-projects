#include<stdio.h>

int seek(int pos,int order[10],int n)
{
	int sum,max,val;
	sum=199-pos;
	max=0;
	for(int i=0;i<n;i++)
	{
		if(order[i]<pos)
		{
			val=order[i];
			if(val>max)
				max=val;
		}
	}
	sum=sum+199+max;
	return sum;
}

int main()
{

	int pos,n,order[10];

	printf("Enter the current position of disk head:");
	scanf("%d",&pos);

	printf("\nEnter number of requests:");
	scanf("%d",&n);

	printf("\nEnter the requests in order:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&order[i]);
	}

	printf("\nTotal seek time:%d",seek(pos,order,n));
	return 0;
}