#include<iostream>
using namespace std;
int main()
{
    int testcase,n,rooks,i,j,k,m;
    cin>>testcase;
    for(i=1;i<=testcase;i++)
    {
        cin>>n>>rooks;
        for(j=1;j<=rooks;j++)
        {
            cin>>k>>m;
        }
        if(n>rooks)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;

}