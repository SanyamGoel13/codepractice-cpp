#include<iostream>
using namespace std;
void tobinary(int dec)
{
    if(dec==0)
    {
        return;
    }
    int num;
    num=dec/2;
    tobinary(num);
    cout<<dec%2;
}
int main()
{
    int dec;
    cin>>dec;
    tobinary(dec);
    return 0;
}