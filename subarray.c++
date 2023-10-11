#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            for(k=i;k<=j;k++)
            {
                cout<<arr[k]<<",";
            }
            cout<<endl;
        }
    }
}
