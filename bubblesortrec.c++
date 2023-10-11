#include<iostream>
using namespace std;
void bubblesort(int arr[],int size, int i)
{ 
    if(i==size-1)
    {
        return;
    }
    if(size==1)
    {
        return;
    }
    if(arr[i]>arr[i+1])
    {
        swap(arr[i],arr[i+1]);
    }
    bubblesort(arr,size,i+1);
    bubblesort(arr,size-1,0);
    
}
int main()
{
    int arr[]={2,7,5,3,8,5};
    int size=sizeof(arr)/sizeof(int);
    bubblesort(arr,size,0);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
}