#include<stdio.h>


/*Declaring function prototypes
fcfs for first come first serve algorithm and sjf for shortest job first
*/

void fcfs(int*,int*,int);
void sjf(int*,int*,int);

//main block
int main()
{
	int i,n,arr_time[10],burst_time[10];
	printf("Enter number of processes:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Arrival time of process %d in ms:",i+1);
		scanf("%d",&arr_time[i]);
		printf("Burst time of process %d in ms:",i+1);
		scanf("%d",&burst_time[i]);
	}
	printf("By FCFS algorithm.\n");
	fcfs(arr_time,burst_time,n);
	printf("\nBy SJF algorithm.\n");
	sjf(arr_time,burst_time,n);

	return 0;


}

//Function declarations.

void fcfs(int *x,int *y,int length)
{
	int comp_time[10],turn_arr_time[10],wait_time[10],order[10],dup[10],first=0,temp,i,j;

	//Creating a duplicate array for storing arrival time.
	for(i=0;i<length;i++)
	{
		dup[i]=x[i];
	}


	//Sorting the newly created array.This will be used to store the order of process.
	for(i=1;i<length;i++)
	{
		for(j=0;j<length-1;j++)
		{
			if(dup[j]>dup[j+1])
			{
				temp=dup[j];
				dup[j]=dup[j+1];
				dup[j+1]=temp;
			}
		}
	}

	//Finding the order of execution 
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(dup[i]==x[j])
			{
				order[i]=j;
				break;
			}
		}
	}


	//Computing the completion time.
	comp_time[0]=x[order[0]]+y[order[0]];
	for(i=1;i<length;i++)
	{
		comp_time[i]=comp_time[i-1]+y[order[i]];
	}



	

	//Finding turn around time and waiting time of each process
	for(i=0;i<length;i++)
	{
		turn_arr_time[i]=comp_time[i]-x[i];
		wait_time[i]=turn_arr_time[i]-y[i];
	}

	//computing Average turnaround time and waiting time

	float sum1=0,sum2=0,avgt,avgw;
	for(i=0;i<length;i++)
	{
		sum1=sum1+turn_arr_time[i];
		sum2=sum2+wait_time[i];
	}

	avgt=sum1/length;
	avgw=sum2/length;

	printf("The Average Turn around time is:%.2fms",avgt);
	printf("\nThe Average Waiting time is:%.2fms",avgw);

	


}

void sjf(int *x,int *y,int length)
{




int comp_time[10],turn_arr_time[10],wait_time[10],order1[10],order2[10],dup1[10],dup2[10],first=0,temp,i,j;

	//Creating a duplicate array for storing burst time.
	for(i=0;i<length;i++)
	{
		dup1[i]=y[i];
		dup2[i]=x[i];
	}


	//Sorting the newly created arrays.These will be used to store the order of process.
	for(i=1;i<length;i++)
	{
		for(j=0;j<length-1;j++)
		{
			if(dup1[j]>dup1[j+1])
			{
				temp=dup1[j];
				dup1[j]=dup1[j+1];
				dup1[j+1]=temp;
			}

			if(dup2[j]>dup2[j+1])
			{
				temp=dup2[j];
				dup2[j]=dup2[j+1];
				dup2[j+1]=temp;
			}
		}
	}

	//Finding the order of execution order1 is the order based on burst time while order2 is based on arrival time.
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(dup1[i]==y[j])
			{
				order1[i]=j;
				break;
			}
		}
	}


	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(dup2[i]==x[j])
			{
				order2[i]=j;
				break;
			}
		}
	}


	//Computing the completion time.
	if(x[order1[0]]<x[order2[0]])
		comp_time[0]=x[order1[0]]+y[order1[0]];
	else
		comp_time[0]=x[order2[0]]+y[order2[0]];

	for(i=1;i<length;i++)
	{
		if(comp_time[i-1]>=x[order1[i]])
			comp_time[i]=comp_time[i-1]+y[order1[i-1]];
		else
			comp_time[i]=comp_time[i-1]+y[order2[i]];
	}

	

	//Finding turn around time and waiting time of each process
	for(i=0;i<length;i++)
	{
		turn_arr_time[i]=comp_time[i]-x[i];
		wait_time[i]=turn_arr_time[i]-y[i];
	}

	//computing Average turnaround time and waiting time

	float sum1=0,sum2=0,avgt,avgw;
	for(i=0;i<length;i++)
	{
		sum1=sum1+turn_arr_time[i];
		sum2=sum2+wait_time[i];
	}

	avgt=sum1/length;
	avgw=sum2/length;

	printf("The Average Turn around time is:%.2fms",avgt);
	printf("\nThe Average Waiting time is:%.2fms",avgw);

}