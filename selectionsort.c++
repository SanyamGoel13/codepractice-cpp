#include<iostream>
using namespace std;
int main()
{
    int arr[6]={9,4,5,2,8,7};
    int i,j,temp,small,t,a;
    for(i=0;i<6;i++)
    {
        small=arr[i];
        t=i;
        for(j=i+1;j<6;j++)
        {
            if(small>arr[j])
            {
                small=arr[j];
                t=j;
            }
        }
        temp=arr[i];
        arr[i]=small;
        arr[t]=temp;
        a=t+1;
        cout<<a;
    }
    cout<<endl;
    for(i=0;i<6;i++)
    {
        cout<<arr[i];
    }
}