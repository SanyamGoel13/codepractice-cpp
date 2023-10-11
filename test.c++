#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(3);
    /*v.push_back(3);
    v.push_back(5);
    v.push_back(4);
    cout<<v[2];
    v[2]=4;
    cout<<v[2];
    v[6]=6;
    cout<<v[5]<<endl;*/
    v[0]=4;
    v[1]=2;
    cout<<v[0]<<v[1];
    return 0;
}