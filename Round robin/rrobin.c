#include<stdio.h>

int main()
{
	int n,i,j,arr_time[10],burst_time[10],comp_time[10],turn_arr_time[10],wait_time[10],dup[10],flg=1,count=0;
	float sum1=0,sum2=0;

	printf("Enter number of process:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter details of process %d",(i+1));
		printf("\nEnter arrival time and burst time:");
		scanf("%d,%d",&arr_time[i],&burst_time[i]);
		dup[i]=burst_time[i];
	}

	while(flg)
	{
		for(i=0;i<n;i++)
		{
			dup[i]=dup[i]-4;
			count=count+4;
			if(dup[i]<4)
			{
				comp_time[i]=count+dup[i];
				flg=0;
			}
			else
				flg=1;
		}
	}

	for(i=0;i<n;i++)
	{
		turn_arr_time[i]=comp_time[i]-arr_time[i];
		wait_time[i]=turn_arr_time[i]-burst_time[i];

		sum1+=turn_arr_time[i];
		sum2+=wait_time[i];
	}

	printf("Average turn around time:%f",sum1/n);
	printf("\nAverage Wait time:%f",sum2/n);
	return 0;

}