#include<iostream>
using namespace std;
int fibonacci(int n)
{
    int i,j;
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    i= fibonacci(n-1) + fibonacci(n-2);
    return i;
    

}
int main()
{
    int n,ans;
    cin>>n;
    ans=fibonacci(n);
    cout<<ans;
    return 0;
    
}