#include<iostream>
using namespace std;
void reversestring(string str)
{
    if(str=="\0")
    {
        return;
    }
    reversestring(&str[1]);
    cout<<str[0];
}
int main()
{
    char arr[100];
    cin.getline(arr,100);
    reversestring(arr);
    return 0;
}