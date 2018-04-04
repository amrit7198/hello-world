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
	printf("Enter number of Processes:");
	scanf("%d",&process_count);
	p1=(struct process_q1*)malloc(sizeof(struct process_q1)*process_count);
	q1=(int*)malloc(sizeof(int)*process_count);
	q2=(int*)malloc(sizeof(int)*process_count);
	burst=(int*)malloc(sizeof(int)*process_count);	
	printf("\n\t\tDetails of Process\n");
	for(int i=0;i<process_count;i++)
	{
		p1[i].pid=i+1;
		printf("\nEnter Arrival time of Process %d:",i+1);
		scanf("%d",&p1[i].a_time);
		printf("Enter Burst time of Process %d:",i+1);
		scanf("%d",&p1[i].b_time);
		burst[i]=p1[i].b_time;
		printf("Enter Priority of Process %d:",i+1);
		scanf("%d",&p1[i].priority);
		p1[i].wait_time=0;
	}
	/*for(int i=0;i<process_count;i++)
	{
		printf("\n%d %d %d %d",p1[i].pid,p1[i].a_time,p1[i].b_time,p1[i].priority);
	}
	for(int i=0;i<process_count;i++)
	printf("%d ",burst[i]);*/
	display();
	free(p1);
	free(q1);
	free(burst);	
}
