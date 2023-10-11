#include<iostream>
using namespace std;
int main()
{
    char letter;
    int i,j,k,n;
    cin>>n;
    for(i=n;i>=1;i--)
    {
        for(j=0;j<=i-1;j++)
        {
            letter='A';
            letter=letter+j;
            cout<<char(letter);
        }
        //for(k=i-1;k>=0;k--)
        for(k=0;k<=i-1;k++)
        {
            cout<<char(letter-k);
        }
        cout<<endl;
    }
    return 0;
    
}