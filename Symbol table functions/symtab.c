#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct symtab
{
	char symname[20],address[10];
};


void insert(struct symtab *sym,int n)
{
	if((n+1)==20)
	{
		printf("Table is full.");
	}
	else
	{
		
		printf("Enter symbol name:");
		scanf("%s",&sym[n-1].symname);

		printf("Enter Address:");
		scanf("%s",&sym[n-1].address);
		
	}

}

void modify(struct symtab *sym ,int pos,char * address)
{	
		
	strcpy(sym[pos-1].address,address);

}

void search(struct symtab *sym,char * name,int n)
{
	int key;
	printf("Symbol name \t address \n");

	for(int i=0;i<n;i++)
	{
		if(strcmp(sym[i].symname,name)==0)
		{
			printf("%s\t",sym[i].symname);
			printf("%s",sym[i].address);
		}
	}


}

void display(struct symtab *sym,int n)
{

	printf("Symbol name \t address \n");

	for(int i=0;i<n;i++)
	{
		printf("%s\t",sym[i].symname);
		printf("%s\n",sym[i].address);
	}
}

int main()
{
	struct symtab table[20];
	int ctr=0,choice,n,pos,flg;
	char name[20],address[10];
	printf("1.Create table \n 2.Insert Entry \n 3.Modify Record \n 4.Search records \n 5.Display Records \n 6.Exit \n");

	do
	{
		printf("Enter your choice(1-6):");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("New symbol table created");
					break;
			case 2:insert(table,ctr+1);
					ctr++;
					break;
			case 3:printf("Enter Record position:");
					scanf("%d",&pos);
					printf("Enter Address:");
					scanf("%s",&address);
					modify(table,pos,address);
					break;
			case 4:printf("Enter symbol name to be searched:");
					scanf("%s",&name);
					search(table,name,ctr+1);
					break;
			case 5:display(table,ctr);
					break;
			case 6:exit(0);
					break;
			default:printf("Wrong choice.Try again.");
					break;

		}

		printf("\nDo you want to continue if yes then Enter 1 otherwise enter 0:");
		scanf("%d",&flg);

	}while(flg);

	return 0;


}