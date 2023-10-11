#include<iostream>
using namespace std;
int binarysearch(int arr[],int key,int start,int end)
{
    int mid=(start+end)/2;
    if(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            return binarysearch(arr,key,mid+1,end);
        }
        else if(arr[mid]>key)
        {
            return binarysearch(arr,key,start,mid-1);
        }
    }
    return -1;
}
int main()
{
    int arr[100];
    int n;
    int key;
    cin>>n;
    cin>>key;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int size=sizeof(arr)/sizeof(int);
    cout<<size<<endl;
    cout<<binarysearch(arr,key,0,n-1);

}
