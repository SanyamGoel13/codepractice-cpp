#include<iostream>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    int i;
    char arr[50];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int j;
    for(i=0;i<t;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[j]=='B'&&arr[j+1]=='G')
            {
                arr[j]='G';
                arr[j+1]='B';
                j++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}