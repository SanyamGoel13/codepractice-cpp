#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s="22";
    int p=1;
    int ans=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    cout<<ans;

}