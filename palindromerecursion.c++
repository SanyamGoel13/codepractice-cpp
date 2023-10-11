#include<iostream>
#include<string>
using namespace std;
bool ispalindrome(string str)
{
    if(str.length()==0 || str.length()==1)
    {
        return true;
    }
    else if(str[0]==str[str.length()-1])
    {
        return ispalindrome(str.substr(1,str.length()-2));
    }
    else
    {
        return false;
    }
}
int main()
{
    char arr[20];
    cin.getline(arr,20);
    if(ispalindrome(arr))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}