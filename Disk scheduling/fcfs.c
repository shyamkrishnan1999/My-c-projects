#include<stdio.h>
#include<stdlib.h>

int seek(int pos,int order[10],int n)
{
	int sum,diff;
	sum=order[0]-pos;

	for(int i=0;i<n-1;i++)
	{
		diff=abs(order[i+1]-order[i]);
		sum=sum+diff;
	}

	return sum;
}

int main()
{
	int pos,order[10],n;

	printf("Enter current position of disk head:");
	scanf("%d",&pos);

	printf("\n Enter number of requests:");
	scanf("%d",&n);

	printf("\n Enter the requests one by one:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&order[i]);

	printf("\n Total seek time:%d",seek(pos,order,n));

	return 0;
}