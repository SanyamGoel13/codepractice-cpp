#include<iostream>
using namespace std;
void subset(char arr[],char output[100],int i, int j)
{
    if(arr[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<" ";
        return;
    }
    output[j]=arr[i];
    subset(arr,output,i+1,j+1);
    subset(arr,output,i+1,j);
}
int main()
{
    char arr[]="sanyam";
    char output[1000];
    subset(arr,output,0,0);
    return 0;
}