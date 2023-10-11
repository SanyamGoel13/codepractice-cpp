#include<iostream>
#include<list>
using namespace std;
template<class forward_iterator,class qwerty>
forward_iterator search(forward_iterator start,forward_iterator end,qwerty key)
{
    while(start!=end)
    {
        if(key==*start)
        {
            return start;
        }
        start++;
    }
    return start;
}
int main()
{
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    auto it=search(l.begin(),l.end(),8);
    if(it==l.end())
    {
        cout<<"not found";
    }
    else
    {
        cout<<*it;
    }
    return 0;
}