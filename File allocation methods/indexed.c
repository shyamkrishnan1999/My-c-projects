#include<stdio.h>
#include<stdlib.h>


int main()
{
	//Here assume that there are 50 memory spaces in which each space contain 10 blocks.
	int i,j,index,n,file[10],choice,count;
	int memory[50][10]={0};

	do{
		printf("Enter the index block:");
		scanf("%d",&index);

		printf("Enter number of files to be placed in index block:");
		scanf("%d",&n);

		count=0;
		for(i=0;i<10;i++)
		{
			if(memory[index][i]==0)
				count++;
		}

		if(n<=count)
		{
			int countn=0;
			printf("File allocated at:");

			for(i=0;i<10;i++)
			{
				if(memory[index][i]==0)
					{
						printf("\nIndex %d->block %d",index,i);
						memory[index][i]=1;
						countn++;
					}
				if(countn==n)
					break;
			}

		}
		else
			printf("Memory not available.");

		printf("\nDo you want to continue if yes then enter 1 else enter 0:");
		scanf("%d",&choice);

	}while(choice);

	return 0;
}