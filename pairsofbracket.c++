#include<iostream>
using namespace std;
void totalstrings(int pairs,char output[],int i,int j,int k)
{
    if(i==2*pairs)
    {
        output[i]='\0';
        cout<<output<<" ";
        return;
    }
    if(j<pairs)
    {
        output[i]='(';
        totalstrings(pairs,output,i+1,j+1,k);
    }
    if(k<j)
    {
        output[i]=')';
        totalstrings(pairs,output,i+1,j,k+1);
    }

}
int main()
{
    int pairs;
    cin>>pairs;
    char output[1000];
    totalstrings(pairs,output,0,0,0);
    return 0;
}