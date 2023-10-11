#include<iostream>
using namespace std;
void merge(int arr[],int s,int e)
{
    
    int mid=(s+e)/2;
    int ne[100];
    int k=mid+1;
    int i=s;
    int z=s;
    while(z<=mid && k<=e)
    {
        if(arr[z]>arr[k])
        {
            ne[i++]=arr[k++];
        }
        else
        {
            ne[i++]=arr[z++];
        }
    }
    while(z<=mid)
    {
        ne[i++]=arr[z++];
    }
    while(k<=e)
    {
        ne[i++]=arr[k++];
    }
    for(i=s;i<=e;i++)
    {
        arr[i]=ne[i];
    }
}
void mergesort(int arr[100],int s,int e)
{
    int mid=(s+e)/2;
    if(s>=e)
    {
        return;
    }
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    return merge(arr,s,e);
}
int main()
{
    int arr[]={2,7,4,5,3,9,4,6};
    int n=sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}