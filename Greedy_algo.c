#include<stdio.h>
#define SIZE 100

struct jobs{
   char jobId[20];
   int start_time;
   int finish_time;
   int compatability;
}jobs[SIZE];

void sort_finish_time(int size)
{
   int temp_start,temp_finish;
   char str[20];

   int i,j;

   for(i=0;i<size;i++)
     for(j=0;j<size-1;j++)
      {
        if(jobs[i].finish_time > jobs[i].)
      }

}
int main()
{
   // freopen("input.txt","r",stdin);

   int i,j,n;
   
   for(i=0;i<n;i++)
     jobs[i].compatability = 1;
  

   printf("Enter number of jobs:");
   scanf("%d",&n);
   printf("Enter informations:\n");
   for(i=0;i<n;i++)
     {
       scanf("%s",&jobs[i].jobId);
       scanf("%d",&jobs[i].start_time);
       scanf("%d",&jobs[i].finish_time);
     }

    printf("\n");
    for(i=0;i<n;i++)
     {
       printf("%s ",jobs[i].jobId);
       printf("%d ",jobs[i].start_time);
       printf("%d ",jobs[i].compatability);
       printf("%d \n",jobs[i].finish_time);
     }
    
}