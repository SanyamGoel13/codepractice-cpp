#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<string,vector<string>,greater<string>> pq;
    pq.push("sanyam");
    pq.push("rahul"); 
    pq.push("ram");
    cout<<pq.top();
    pq.pop();
    cout<<endl;
    cout<<pq.top();
}