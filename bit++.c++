#include<iostream>
using namespace std;
int main()
{
    int n,i,j,x=0,temp=0;
    char arr[n][3];
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]=='+') 
            {
                x++;
                break;
                temp=1;
            }
            if(temp=0)
            {
                x--;
            }
        }
    }
    cout<<x;
    return 0;


}