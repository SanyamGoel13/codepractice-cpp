#include<iostream>
using namespace std;
char arr[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void numtospell(int num)
{
    if(num==0)
    {
        return;
    }
    int n=num%10;
    numtospell(num/10);
    cout<<arr[n]<<" ";
}
int main()
{
    int num;
    cin>>num;
    numtospell(num);
    return 0;

}