#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int main()
{
    string s="bbbbb";
    int i;
    bool a=0;
    for(i=0;s[i]!='\0';i++);
    int size=1;
    int longestsize=1;
    string v;
    for(int j=1;j<=i-1;j++)
    {
        a=0;
        for(int k=0;k<j;k++)
        {
            if(s[k]!=s[j])
            {
                a=1;
            }
            else
            {
                size=1;
                a=0;
            }
           // if(a!=0){
           // size++;
            //longestsize=size;}
        }
        if(a==1){
            size++;
            
            longestsize=max(longestsize,size);
        }    //cout<<longestsize<<endl;}
    }
    cout<<i<<endl;
    cout<<longestsize;


}