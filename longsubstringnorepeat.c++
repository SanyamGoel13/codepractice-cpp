#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    string s="pwwkew";
    unordered_map<char,int> mapi;
    int max_count=0;
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(mapi.count(s[i]) && i-mapi[s[i]]<=count)
        {
            max_count=max(count,max_count);
            count=i-mapi[s[i]];
            mapi[s[i]]=i;
        }
        else
        {
            count++;
            mapi[s[i]]=i;
        }
    }
    max_count=max(max_count,count);
    cout<<max_count;

}