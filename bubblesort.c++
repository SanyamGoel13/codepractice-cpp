#include<iostream>
using namespace std;
int main()
{
    int arr[7]={2,4,3,8,4,5,9};
    int i,j,temp;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<7;i++)
    {
        cout<<arr[i];
    }
}