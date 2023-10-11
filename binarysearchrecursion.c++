#include<iostream>
using namespace std;
int binarysearch(int arr[],int key,int start,int end)
{
    int mid=(start+end)/2;
    if(start>end)
    {
        return -1;
    }   
    if(key==arr[mid])
    {
        return mid+1;
    }
    else if(key>arr[mid])
    {
        return binarysearch(arr,key,mid+1,end);
    }
    else
    {
        return binarysearch(arr,key,start,mid-1);
    }
   
}
int main()
{
    int arr[20];
    int i;
    int n,key;
    cin>>n>>key;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binarysearch(arr,key,0,n-1);
}