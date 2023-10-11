//maximum sum of the subarray
#include<iostream>
using namespace std;
int maximum_sum(int arr[],int n)
{
    int csum=0, maxsum=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        csum=csum + arr[i];
        if(csum<0)
        {
            csum=0;
        }
        maxsum=max(maxsum,csum);
    }
    return maxsum;
}
int main()
{
    int n,i,ans;
    int arr[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ans=maximum_sum(arr,n);
    cout<<ans;
}