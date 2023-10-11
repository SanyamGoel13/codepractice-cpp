#include<iostream>
using namespace std;
int power(int a, int b)
{
    //base case
    int ans;
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    ans=power(a,b/2);
    if(b%2==0)
    {
        return ans*ans;
    }
    else
    {
        return a*(ans*ans);
    }
}
int main()
{
    int number, raisetopower;
    cin>>number>>raisetopower;
    int ans;
    ans=power(number,raisetopower);
    cout<<ans;
    return 0;
}