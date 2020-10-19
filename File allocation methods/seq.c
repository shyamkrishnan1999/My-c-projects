#include<stdio.h>
#include<stdlib.h>

int main()
{
	int f[50],i,j,begin,length,count,choice;

	for(i=0;i<50;i++)
		f[i]=0;

	x:count=0;
	printf("Enter the begining index and length of record:");
	scanf("%d,%d",&begin,&length);

	if((begin==50&&length>1)||begin>50)
		printf("Out of Bounds.Allocation not possible.");

	for(i=begin;i<begin+length;i++)
	{
		if(f[i-1]==0)
			count++;
	}

	if(count==length)
	{
		printf("Allocation sucessful.\n");

		for(i=begin;i<begin+length;i++)
			{
				f[i-1]=1;
				printf("%d \t %d \n",i,f[i-1]);
			}
	}
	else
		printf("Allocation Failed.Memory space is already occupied.\n");

	printf("\nDo you want to continue if yes then type 1 else type 0:");
	scanf("%d",&choice);

	if(choice==1)
		goto x;
	else
		exit(0);


	return 0;


}