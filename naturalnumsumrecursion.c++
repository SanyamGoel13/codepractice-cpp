#include<iostream>
using namespace std;
int naturalnumsum(int num)
{
    if(num==1)
    {
        return 1;
    }
    return num+naturalnumsum(num-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<naturalnumsum(n);
}