#include<iostream>
#include<string.h>
using namespace std;
int stringtoint(char arr[],int size)
{
    if(size==0)
    {
        return 0;
    }
    int num=arr[size-1]-'0';
    return stringtoint(arr,size-1)*10+num;
}
int main()
{
    char arr[]="1234";
    int size=sizeof(arr)/sizeof(char);
    size--;
    int i=stringtoint(arr,size);
    cout<<i;
}