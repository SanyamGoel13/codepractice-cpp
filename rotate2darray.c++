#include<iostream>
using namespace std;
int main()
{
    int arr[100][100];
    int n;
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int rotatedarray[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            rotatedarray[i][j]=arr[j][n-1-i];
        }
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<rotatedarray[i][j]<<" ";
        }
        cout<<endl;
    }
}