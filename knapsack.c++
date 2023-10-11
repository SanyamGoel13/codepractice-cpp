#include<iostream>
using namespace std;
int profit(int weightarr[],int pricearr[],int capacity,int n)
{
    if(n==0|| capacity==0)
    {
        return 0;
    }
    int inc=0;
    int exc=0;

    if(weightarr[n-1]<capacity)
    {
        inc=pricearr[n-1]+profit(weightarr,pricearr,capacity=capacity-weightarr[n-1],n-1);
    }
    exc=profit(weightarr,pricearr,capacity,n-1);
    int ans=max(inc,exc);
    return ans;
}
int main()
{
    int weight[]={1,2,3,5};
    int price[]={40,20,35,100};
    int i=profit(weight,price,7,4);
    cout<<i;
    return 0;
}
