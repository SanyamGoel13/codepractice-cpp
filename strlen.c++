#include<iostream>
using namespace std;
int main()
{
    int i,j,k,l=0,n;
    int arr[3];
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=2;j++)
        {
            cin>>arr[j];
            k=k+arr[j];
        }
        if(k>=2)
        {
            l++;
        }
        k=0;
    }
    cout<<l;

}