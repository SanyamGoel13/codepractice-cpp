#include<iostream>
using namespace std;
bool rakhpaye(int m,int no_of_stables, int mid,int arr[])
{
    int last_cow=arr[0];
    int cnt=1;
    for(int i=1;i<no_of_stables;i++)
    {
        if(arr[i]-last_cow>=mid)
        {
            cnt++;
            last_cow=arr[i];
        }
        if(cnt==m)
        {
            return true;
        }
    }
    return false;
    
}
int maximumdistance(int arr[],int no_of_stables,int m)
{
    int s=0;int ans=0;
    int e=arr[no_of_stables-1]-arr[0];
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(rakhpaye(m,no_of_stables,mid,arr))
        {
            ans=mid;
            s=mid+1;
        } 
        else
        {
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
    int cows;
    int no_of_stables;
    cin>>no_of_stables>>cows;
    int arr[1000];
    for(int i=0;i<no_of_stables;i++)
    {
        cin>>arr[i];
    }
    cout<<maximumdistance(arr,no_of_stables,cows);
    return 0;
}