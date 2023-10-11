//RAT IN A MAZE (BACKTRACKING)
#include<iostream>
using namespace std;
bool rat_in_a_maze(char maze[10][10],int sol[10][10],int i,int j,int m, int n)
{
    if(i==m&&j==n)
    {
        sol[m][n]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(maze[i][j]=='x')
    {
        return false;
    }
    if(i>m||j>n)
    {
        return false;
    }
    sol[i][j]=1;
    bool right=rat_in_a_maze(maze,sol,i,j+1,m,n);
    bool left=rat_in_a_maze(maze,sol,i+1,j,m,n);
    sol[i][j]=0;
    if( right ||left)
    {
        return true;
    }
    return false;
}
int main()
{
    char maze[10][10]={"0000","00x0","000x","0x00",};
    int sol[10][10]={0};
    bool ans=rat_in_a_maze(maze,sol,0,0,3,3);
    if(ans==0)
    {
        cout<<"no road found";
    }
}