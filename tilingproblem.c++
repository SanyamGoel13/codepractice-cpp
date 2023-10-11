#include<iostream>
using namespace std;
int noofways(int n)
{
    if(n<4)
    {
        return 1;
    }
    if(n==4)
    {
        return 2;
    }
    return noofways(n-1)+noofways(n-4);
}
int main()
{
    int lengthofwall;
    cin>>lengthofwall;
    cout<<noofways(lengthofwall);

}