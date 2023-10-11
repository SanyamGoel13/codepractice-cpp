#include<iostream>
using namespace std;
int binary_search(int arr[],int key,int length)
{
    int start=0;
    int end=length-1;
    int mid=start+ (end-start)/2;
    for(;start<=end;)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main()
{
    int arr[6]={2,4,5,7,8,9};
    int length=6;
    int key;
    cin>>key;
    int ans;
    ans=binary_search(arr,key,length);
    cout<<ans;
    return 0;
}