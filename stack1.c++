#include<iostream>
#include<stack>
using namespace std;
bool isvalid(string s)
{
    stack<char> sc;
    //int size=s.size();
    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            sc.push(ch);
        }
        else if(ch==')')
        {
            if(sc.empty()||sc.top()!='(')
            {
                return false;
            }
            sc.pop();
        }
    }
    return sc.empty();
}
int main()
{
    char s[]="((a+b))+(c-d+f))";
    cout<<isvalid(s);
    return 0;
}