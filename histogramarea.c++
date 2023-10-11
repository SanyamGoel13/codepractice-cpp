#include<iostream>
#include<climits>
#include<stack>
using namespace std;
int histogramarea(int arr[],int size)
{
    stack<int> stc;
    int maxarea=INT_MIN;
    int areaheight;
    int top;
    int i=0;
    while(i<size)
    {
        if(stc.empty()|| arr[stc.top()]<=arr[i])
        {
            stc.push(i++);
        }
        else
        {
            top=stc.top();
            stc.pop();
            areaheight=stc.empty()?arr[top]*i:arr[top]*(i-stc.top()-1);
            maxarea=max(maxarea,areaheight);
        }
    }
    while(!stc.empty())
    {
        top=stc.top();
        stc.pop();
        areaheight=stc.empty()?arr[top]*i:arr[top]*(i-stc.top()-1);
        maxarea=max(maxarea,areaheight);

    }
    return maxarea;
}
int main()
{
    int arr[]={6,2,5,4,5,1,6};
    int size=sizeof(arr)/sizeof(int);
    cout<<histogramarea(arr,size)<<endl;
}