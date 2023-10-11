#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j,k;
    cin>>n;
    string words[n];
    for(i=0;i<n;i++)
    {
        cin>>words[i];
    }
    for(i=0;i<n;i++)
    {
        j=words[i].size();
        if(j>10)
        {
            words[i]=words[i].at(0)+to_string(j-2)+words[i].at(j-1);
        }
        cout<<words[i]<<endl;
    }
    return 0;
}