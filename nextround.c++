#include<iostream>
using namespace std;
int next_score(int array[],int k)
{
    if(array[k+1]==array[k])
    {
        k++;
        next_score(array,k);
    }
    else
    {
        return k;
    }
}
int positive_score(int array[],int k)
{
     if(array[k]<=0)
    {
        k--;
        positive_score(array,k);
    }
    else
    {
        return k;
    }
}
int next_score(int*, int);
int positive_score(int*, int);
int main()
{
    int n,k,i,j,l;
    cin>>n>>k;
    int score[n];
    l=k-1;
    for(i=0;i<n;i++)
    {
        cin>>score[i];
    }
    if(score[l]>0)
    {
        j=next_score(score,l);
    }
    else
    {
        j=positive_score(score,l);
    }
    j++;
    cout<<j<<endl;

}