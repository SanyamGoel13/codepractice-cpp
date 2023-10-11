#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cin>>n;
    int key;
    cin>>key;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==key)
            {
                cout<<i<<j<<endl;
            }
        }
    }
     
}