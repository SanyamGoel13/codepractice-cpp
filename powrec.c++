//a^n
#include<iostream>
using namespace std;
/*int power(int num,int pow)
{
    if(pow==0)
    {
        return 1;
    }
    return num*power(num,pow-1);
}*/
int power1(int num,int pow)
{
    if(pow==1)
    {
        return num;
    }
    int p=pow;
    pow=pow/2;
    int ans=power1(num,pow);
    if(p%2==0)
    {
    return ans*ans;
    }
    else
    {
        return num*ans*ans;
    }
}
int main()
{
    int num,pow;
    cin>>num>>pow;
    cout<<power1(num,pow);
}