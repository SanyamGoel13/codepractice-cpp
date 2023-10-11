#include<stdio.h>
int fun(int[]);
int main()
{
    int arr[]={1,2,3};
    int av = fun(arr);
    printf("%d",av);
    return 0;
}
int fun(int array[])
{
    int i;
    int sum=0;
    for(i=0;i<=2;i++)
    {
       sum=sum+array[i] ;
    }
    return sum/i;
}