#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[10000];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    deque<int> que(k);
    for(i=0;i<k;i++)
    {
        while(!que.empty()&& arr[i]>arr[que.back()])
        {
            que.pop_back();
        }
        que.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<arr[que.front()]<<" ";
        while(!que.empty()&&que.front()<=i-k)
        {
            que.pop_front();
        }
        while(!que.empty()&& arr[i]>arr[que.back()])
        {
            que.pop_back();
        }
        que.push_back(i);

    }
    cout<<arr[que.front()]<<" ";
}