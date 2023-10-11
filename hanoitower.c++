//hanoi tower
#include<iostream>
using namespace std;
void move(int n, char init,char help,char final)
{
    if(n==0)
    {
        return;
    }
    move(n-1,init,final,help);
    cout<<"move"<<n<<"th ring from"<<init<<"to"<<final<<endl;
    move(n-1,help,init,final);
}
int main()
{
    int n;
    cin>>n;
    move(n,'A','B','C');
    return 0;
}