#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        k=i;
        for(j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(j=1;j<=2*i-1;j++)
        {
            if(k<=2*i-1)
            {
                cout<<k;
                k++;
            }
            else
            {
                if(k>2*i-1)
                {
                    k--;
                }
                else
                {
                    k--;
                    cout<<k;   
                }
            }    
        }
        cout<<endl;
    }
    return 0;

}