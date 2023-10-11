#include<iostream>
using namespace std;
void merge(int arr[],int s,int p,int e)
{
    int output[100];
    int j=s;
    int k=s;
    int z=p;
    while(s<z && p<=e)
    {
    if(arr[s]<arr[p])
    {
        output[j++]=arr[s++];
    }
    else
    {
        output[j++]=arr[p++];
    }
    }
    while(s<z)
    {
        output[j++]=arr[s++];
    }
    while(p<=e)
    {
        output[j++]=arr[p++];
    }
    while(k<=e)
    {
        arr[k]=output[k];
        k++;
    }

}
void mergesort(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    if(s>=e)
    {
        return;
    }
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    return merge(arr,s,mid+1,e);
}
int main()
{
    int arr[]={1,5,2,6,3,0};
    int size=sizeof(arr)/sizeof(int);
    mergesort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
}