//Longest palindromic substring
#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
int main()
{
    string s="aabaaefabcdedcbaghhgi";
    unordered_map<char,stack<int>> mapi;
    int length=0;
    int longestlength=0;
    int p;int n;
    string longpalindrome;
    for(int i=0;i<s.length();i++)
    {
        if(!mapi.count(s[i]) || (mapi.count(s[i]) && i-(mapi[s[i]].top())>2))
        {
            mapi[s[i]].push(i);
        }
        else
        {
            //if(i-(mapi[s[i]].top())>1)
            //{
                int next=i;
                int pre=mapi[s[i]].top();
                //if(next<s.length()-1) next++;
                //if(pre>0) pre--;
                while(s[next]==s[pre])
                {
                    if(next<s.length()-1 && pre>0)
                    {
                        next++;
                        pre--;
                    }
                    else
                    {
                        break;
                    }
                }
                cout<<next<<" "<<pre<<" ";
                length=next-pre;
                if(length>longestlength)
                {
                    p=pre;
                    n=next;
                }
            //}
            //else
            //{

            //}
        }
    }
    for(int j=p;j<=n;j++)
    {
        cout<<s[j];
    }
}