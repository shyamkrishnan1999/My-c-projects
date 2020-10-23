#include<stdio.h>
#include<stdlib.h>


int main()
{
	int i,j,count=0,start,n=0,list[50],choice,occupied[50],next[50];

	do{

	printf("Enter The starting address and length of record:");
	scanf("%d,%d",&start,&n);

	if(start>50||n>50)
		printf("Out of Bounds.File allocation not possible.");

	for(i=0;i<n-1;i++)
	{
		printf("\nEnter the memory location:");
		scanf("%d",&list[i]);
		if(list[i]>50)
		{
			printf("Out of Bounds.File allocation not possible.");
			exit(0);
		}

	}

		for(i=0;i<n-1;i++)
		{
			if(occupied[list[i]]!=1)
				count++;
		}

		if(count==n-1)
		{
			for(i=0;i<n-1;i++)
			{
				next[i]=list[i+1];
				occupied[i]=1;
			}

			occupied[n-2]=1;
			next[n-2]=0;
			printf("Record inserted sucessfully at:%d->",start);

			for(i=0;i<n-1;i++)
			{
				printf("%d->",list[i]);
			}
		}
		else
			printf("memory not available.");
	
	printf("\nDo you continue if yes then enter 1 else enter 0:");
	scanf("%d",&choice);

	}while(choice);

	return 0;

}