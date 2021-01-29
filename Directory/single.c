#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dir
{
	char dir[10],ch[10][10];
	int f;
};

int main()
{
	int flg=0,nf,i,j,k,d;
	char name[10];
	struct dir dr[10];

	printf("Enter number of directories:");
	scanf("%d",&d);

	if(d>10)
	{
		printf("Size exceeded.Max size is 10");
		exit(0);
	}
	else
	{
		for(i=0;i<d;i++)
		{
			printf("Enter the directory name:");
			scanf("%s",dr[i].dir);

			printf("Enter number of files:");
			scanf("%d",&dr[i].f);

		for(k=0;k<dr[i].f;k++)
		{	
			printf("Enter file name:");
			scanf("%s",name);
			nf=0;

			for(j=0;j<dr[i].f;j++)
			{
				if(strcmp(name,dr[k].ch[j]))
					continue;
				else
				{
					printf("File name already exists.");
					exit(0);
				}

			}

			strcpy(dr[i].ch[k],name);

		}

		printf("Directory %d:%s",(i+1),dr[i].dir);
		printf("\n");

		for(k=0;k<dr[i].f;k++)
		{
			printf("File %d:%s",(k+1),dr[i].ch[k]);
			printf("\n");
		}

		}
	}

	


	return 0;
}