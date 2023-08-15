#include<stdio.h>
#define SIZE 100000
int array[SIZE];

void initialize_array()
{
    for(int i=0;i<SIZE;i++)
        array[i] = -1;
}
int fibo(int num)
{
    if(num == 0)
      return 0;
    if(num == 1)
      return 1;

    if(array[num] != -1)
    {
       return array[num];
    }
    else{
    array[num] = fibo(num-1) + fibo(num-2);
    return fibo(num-1) + fibo(num-2);
    }
}

int main()
{
  initialize_array();
  int num;
  printf("Enter the number to find the Fibonnacci series:");
  scanf("%d",&num);
   for(int i=0;i<num;i++)
     printf("%d ",fibo(i));


}
