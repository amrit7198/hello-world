#include<stdio.h>
#include<stdlib.h>

int process_count;							//total process count
int queue1_size=-1;
int queue2_size=-1;

struct process_q1{
int pid;
int a_time;
int b_time;
int priority;
int wait_time;
int turnaround_time;
}*p1;

int *burst;								//temp burst time storage
int *q1;
int *q2;
int main()
{
	int temp;
	while(1)
	{
		printf("Enter number of Processes:");
		scanf("%d",&temp);
		if(temp>0)
		{
			process_count=temp;
			break;
		}
		else
		{
			printf("Error:Only enter positive number greater than 0.\n\n");
		}
	}
	p1=(struct process_q1*)malloc(sizeof(struct process_q1)*process_count);
	q1=(int*)malloc(sizeof(int)*process_count);
	q2=(int*)malloc(sizeof(int)*process_count);
	burst=(int*)malloc(sizeof(int)*process_count);	
	printf("\n\t\tDetails of Processes\n");
	for(int i=0;i<process_count;i++)
	{
		p1[i].pid=i+1;
		while(1)
		{
			printf("\nEnter Arrival time of Process %d:",i+1);
			scanf("%d",&temp);
			if(temp>=0)
			{
				p1[i].a_time=temp;
				break;
			}
			else
			{
				printf("Error:Only enter positive numbers.\n");
			}
		}
		while(1)
		{
			printf("Enter Burst time of Process %d:",i+1);
			scanf("%d",&temp);
			if(temp>0 && temp%2==0)
			{
				p1[i].b_time=temp;
				break;
			}
			else
			{
				printf("Error:Only enter positive numbers more than 0 which are multiples of 2.\n\n");
			}
		}
		burst[i]=p1[i].b_time;
		while(1)
		{
			printf("Enter Priority of Process %d:",i+1);
			scanf("%d",&temp);
			if(temp>=0)
			{
				p1[i].priority=temp;
				break;
			}
			else
			{
				printf("Error:Only enter positive numbers.\n\n");
			}
		}
		p1[i].wait_time=0;
	}
	display();
	free(p1);
	free(q1);
	free(burst);
	free(q2);	
}
