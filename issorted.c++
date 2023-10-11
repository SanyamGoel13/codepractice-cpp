#include<iostream>
using namespace std;
int main()
{
    int i,n,temp=0;
    cin>>n;
    int *arr = new int[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"array is not sorted"<<endl;
            temp=1;
            break;
        }
    }
    if(temp==0)
    {
        cout<<"array is sorted"<<endl;
    }


}