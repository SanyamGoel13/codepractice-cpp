#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int num=0;
        int maxi=0;
        int arr[100];
        for(int k=0;k<n;k++)
        {
            cin>>arr[k];
        }
        for(int k=1;k<n;k++)
        {
            if(arr[k]==1)
            {
                num=0;
            }
            else
            {
                num++;
                maxi=max(num,maxi);
            }
        }
        cout<<maxi;

    }
}