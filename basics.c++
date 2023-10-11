#include<iostream>
using namespace std;
int main()
{
    int arr[1000][1000];
    int m=3,n=3;
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
    return 0;
}