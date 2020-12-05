#include<stdio.h>
#include<stdlib.h>

int seek(int pos,int order[10],int n)
{
	int sum,diff,min,val;
	sum=199-pos;
	min=pos;
	for(int i=0;i<n-1;i++)
	{
		if(order[i+1]<pos)
		{
			val=order[i+1];
			if(val<min)
				min=val;
		}
					
	}
	sum=sum+(199-min);
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