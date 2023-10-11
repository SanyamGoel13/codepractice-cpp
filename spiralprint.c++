#include<iostream>
using namespace std;
spiralprint(int arr[][100], int m, int n)
{
   int startrow=0;
   int endrow=m-1;
   int startcol=0;
   int endcol=n-1;
   int i,j;
   while(startrow<=endrow && startcol<=endcol )
   {
       for(i=startcol;i<=endcol;i++)
       {
           cout<<arr[startrow][i]<<" ";
       }
       startrow++;
       for(i=startrow;i<=endrow;i++)
       {
           cout<<arr[i][endcol]<<" ";
       }
       endcol--;
       for(i=endcol;i>=startcol;i--)
       {
            cout<<arr[endrow][i]<<" ";  
       }
       endrow--;
       for(i=endrow;i>=startrow;i--)
       {
           cout<<arr[i][startcol]<<" ";
       }
       startcol++;
   }
}
int main()
{
    int arr[100][100];
    int m,n;
    cin>>m>>n;
    int i=1;
    int row,col;
    for(row=0;row<m;row++)
    {
        for(col=0;col<n;col++)
        {
            arr[row][col]=i;
            i++;
        }
    }
    for(row=0;row<m;row++)
    {
        for(col=0;col<n;col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    spiralprint(arr,m,n);
    return 0;
}