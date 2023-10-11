#include<iostream>
using namespace std;
int main()
{
    int t,i,j,k,monsters,small,element,time;
    int health[monsters];
    int spellstrength[monsters];
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>monsters;
        for(j=0;j<monsters;j++)
        {
            cin>>health[j];
        }
        for(j=0;j<monsters;j++)
        {
            cin>>spellstrength[j];
        }
        small=spellstrength[0];
        for(k=0;k<monsters;k++)
   { 
        for(j=0;j<monsters-k;j++)
        {
            if(small>spellstrength[j])
            {
                small=spellstrength[j];
                element=j;
            }
        }
        time=health[j];
        health[j-1]=health[j-1]+spellstrength[j];
        health[j+1]=health[j+1]+spellstrength[j];

    }


    }
}