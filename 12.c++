#include<iostream>
#include<string>
using namespace std;
int main()
{
        string s="2147483647";
        long long int ans=0;
        //int ans1;
        int num;
        int i=0;
        int neg=0;
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]=='-')
        {
            neg=1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        while(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            num=s[i]-'0';
            
            if(ans>=214748364 && neg==0)
            {
                //cout<<"hi";
                if(ans>214748364)
                {
                    ans=2147483647;
                    break;
                    cout<<"hi";
                    
                }
                else if(ans==21478364 && num>=7)
                {
                    ans=2147483647;
                    cout<<"hi";
                break;
                }
            }
            else if(ans>214748364 && neg==1)
            {
                if(ans>214748364){
                ans=2147483648;
                break;}
                else if(ans=21478364 && num>=8)
                {
                    ans=2147483648;
                break;
                }
            }
            //cout<<ans<<endl;
            ans=ans*10+num;
            i++;
        }
        if(neg==1)
        {
            ans=ans*-1;
        }
        cout<<ans<<endl;
        //ans1=ans;
        //cout<<ans1;
}