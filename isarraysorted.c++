//is array sorted using recursion
#include<iostream>
using namespace std;
bool issorted(int arr[],int size,int index)
{
    if(index==size-1)
    {
        return true;
    }
    if(arr[index]<=arr[index+1])
    {
        return issorted(arr,size,index+1);
    }
    return false;
}
bool Issorted(int* arr,int size)
{
    if(size==1||size==0)
    {
        return true;
    }
    if(arr[0]<=arr[1])
    {
        return Issorted(arr+1,size-1);
    }
    return false;
}
int main()
{
    int arr[]={1,4,9,11,12};
    int n=sizeof(arr)/sizeof(int);
    if(Issorted(arr,n))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
}