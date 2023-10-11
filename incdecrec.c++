//inc function using c++
#include<iostream>
using namespace std;
void inc_fun(int n)
{
    if(n==0)
    {
        return;
    }
    inc_fun(n-1);
    cout<<n<<" ";

}
void dec_fun(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    dec_fun(n-1);
    

}
int main()
{
    int n;
    cin>>n;
    inc_fun(n);
    cout<<endl;
    dec_fun(n);
}