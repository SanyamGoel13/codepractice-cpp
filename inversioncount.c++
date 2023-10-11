//inversion count
#include<iostream>
using namespace std;
int count(int arr[],int s,int e)
{
    int output[10000];
    int j=s;
    int mid=(s+e)/2;
    int p=mid+1;
    //int k=s;
    int i=s;
    int z=p;
    int cnt=0;
    while(i<z && p<=e)
    {
    if(arr[i]<=arr[p])
    {
        output[j++]=arr[i++];
    }
    else
    {
        output[j++]=arr[p++];
        cnt +=  mid-i+1;
    }
    }
    while(i<z)
    {
        output[j++]=arr[i++];
    }
    while(p<=e)
    {
        output[j++]=arr[p++];
    }
    for(i=s;i<=e;i++)
    {
        arr[i]=output[i];
    }
    return cnt;

}
int inversioncount(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    if(s>=e)
    {  
        return 0;
    }
    int x=inversioncount(arr,s,mid);
    int y=inversioncount(arr,mid+1,e);
    return x+y+count(arr,s,e); 

}
int main()
{
    int arr[]={1,5,2,6,3,0};
    int size=sizeof(arr)/sizeof(int);
    cout<<inversioncount(arr,0,size-1);
}