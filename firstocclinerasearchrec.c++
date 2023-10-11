//first occurence of key in array using recursion and linear search
#include<iostream>
using namespace std;
int firstocc(int *arr,int key,int size)
{
    
    int ans=0;
    if(size==0)
    {
        return -1;
    }
    if(arr[0]==key)
    {
        return 0;
    }
    ans=firstocc(arr+1,key,size-1)+1;
    if(ans==0)
    {
        return -1;
    }
    return ans;
}
int firstoccloop(int arr[],int key,int size,int index)
{
    if(index==size-1)
    {
        return -1;
    }
    if(arr[index]==key)
    {
        return index;
    }
        return firstoccloop(arr,key,size,index+1);
    
}
int main()
{
    int arr[]={5,4,5,7,5,3,7,8,5,9};
    int size =sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    cout<<firstocc(arr,key,size);
}