/*
Name :-	Gauri Gholap
Title	:-	Write a program to solve optimal storage 
on tapes problem using Greedy approach.

		(Multi Tape)
*/

#include<stdio.h>

void sort(int arr[],int n);
void findOptimalStorage(int arr[],int n,int t);

int main()
{
	int arr[20],n,i,t;
	
	for(i=0;i<20;i++)
	{
		arr[i]=0;
	}
	
	printf("\n How many Program you want to store ? ");
	scanf("%d",&n);
	
	printf("\n Hoew many tape you want use ? ");
	scanf("%d",&t);
	
	printf("\n Enter %d Programs \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	sort(arr,n);
	findOptimalStorage(arr,n,t);
	
	return 0;
}

void sort(int arr[20],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\n Programs in sequence : \n");
	for(i=0;i<n;i++)
	{
		printf("\t %d",arr[i]);
	}
}

void findOptimalStorage(int arr[20],int n,int t)
{
	int i,j,k=n,k1=0,kk=0;
	int tape[10][n];
	int minTime=0,sum=0;

	j=(n/2)+1;

	while(j>=0)
	{	
		for(i=0;i<t;i++)
		{		
			tape[i][k1]=arr[kk];
			kk++;
		}
		k1++;	j--;	
	}

	printf("\n Tapes contain :\n");
	for(i=0;i<t;i++)
	{
		printf("\n Tape %d : ",i+1);
		for(j=0;j<k1;j++)
		{
			printf("\t %d ",tape[i][j]);
		}
	}
	k1--;
	for(i=0;i<t;i++)
	{
		sum=0;
		for(j=0;j<k1;j++)
		{
			for(kk=0;kk<=j;kk++)
			{
				if(tape[i][j]>0)
				{
					sum=sum+tape[i][kk];
				}				
			}	
		}	
		minTime=minTime+sum;
	}
	printf("\n Optimal Storage : %d",minTime);
	printf("\n Optimal Storage : %0.2f",((float)minTime/t));
}
/*
Output :

 How many Program you want to store ? 5

 Hoew many tape you want use ? 2

 Enter 5 Programs
4
6
7
5
2

 Programs in sequence :
         2       4       5       6       7
 Tapes contain :

 Tape 1 :        2       5       7       0
 Tape 2 :        4       6       0       0
 
 Optimal Storage : 37
 Optimal Storage : 18.50
 
*/
