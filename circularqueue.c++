#include<iostream>
using namespace std;
class queue
{
    private:
    int *arr;
    int fron,rear,cs,ms;
    public:
    queue(int d=5)
    {
        arr=new int[d];
        fron=0;
        rear=d-1;
        cs=0;
        ms=d;
    }
    bool full()
    {
        return cs==ms;
    }
    bool empty()
    {
        return cs==0;
    }
    void push(int d)
    {
        if(!full())
        {
            rear=(rear+1)%ms;
            arr[rear]=d;
            cs++;
        }
    }
    void pop()
    {
        if(!empty())
        {
            fron=(fron+1)%ms;
            cs--;
        }
    }
    int front()
    {
        if(!empty())
        {
            return arr[fron];
        }
    }
    ~queue()
    {
        if(arr!=NULL)
        {
            delete [] arr;
            arr==NULL;
        }
    }
};
int main()
{
    queue q;
    for(int i=1;i<=6;i++)
    {
        q.push(i);
    }
    q.pop();
    q.pop();
    cout<<q.front();
    cout<<endl;
    q.push(8);
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
}