#include<iostream>
using namespace std;
int pivot(int arr[],int s,int e)
{
    int p=arr[e];
    int i=s-1;
    int j=s;
    for(;j<=e;j++)
    {
        if(arr[j]<p)
        {
            i=i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;

}
void quicksort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p= pivot(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main()
{
    int arr[]={2,5,3,9,6,7,8,1,4,1};
    int size=sizeof(arr)/sizeof(int);
    quicksort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
}