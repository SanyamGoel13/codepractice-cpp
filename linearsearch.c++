#include<iostream>
using namespace std;
int main()
{
    int arr[1000];
    int n,key,flag=0;
    cout<<"enter length of array and key"<<endl;
    cin>>n>>key;
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            j=i;
            j++;
            cout<<"key is present at"<<j<<endl;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"key is not present";
    }
}