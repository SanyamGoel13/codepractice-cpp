#include<iostream>
using namespace std;
int main()
{
    int x=123;
    int ans;
        int flag=0;
        int count=0;
        while(x>0)
        {
            count++;
            int num=x%10;
            x=x/10;
            if(flag==1)
            {
                ans=0;
                break;
            }
            else if(flag==2 && num>7)
            {
                ans=0;
                break;
            }
            ans=ans*10+num;
            if(count==9)
            {
                if(ans>214748364)
                {
                    flag=1;
                }
                else if(ans==214748364)
                {
                    flag=2;
                }
            }
        }
        cout<<ans;
}