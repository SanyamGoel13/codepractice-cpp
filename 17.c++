#include<iostream>
void printleft(node* head)
{
    while(true)
    {
        if(!isleaf())
        {
            
        }
    }
}
using namespace std;
int main()
{
    int arr[1000][1000];
    int m,n;
    int i=1;
    cin>>m>>n;
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
}