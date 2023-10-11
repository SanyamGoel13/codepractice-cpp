#include<iostream>
#include<vector>
using namespace std;
class heap
{
    private:
    vector<int> v;
    bool min_heap;
    bool compare(int ind,int parent)
    {
        if(min_heap)
        {
            return v[ind]<v[parent];
        }
        return v[ind]>v[parent];
    }
    void heapify(int index)
    {
        int left=2*index;
        int right=left+1;
        int last=v.size()-1;
        int req_index=index;
        if(left<=last && compare(left,index))
        {
            req_index=left;
        }
        if(right<=last && compare(right,req_index))
        {
            req_index=right;
        }
        if(req_index!=index)
        {
            swap(v[req_index],v[index]);
            heapify(req_index);
        }
    }
    public:
    heap(int size=10,bool ans=true)
    {
        v.reserve(size);
        v.push_back(-1);
        min_heap=ans;
    }
    void push(int d)
    {
        v.push_back(d);
        int index=v.size()-1;
        int parent=index/2;
        while(index>1 && compare(index,parent))
        {
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size()==1;
    }
};
int main()
{
    heap h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        h.push(no);
    }
    while(!h.empty())
    {
        //int no;
        //cin>>no;
        cout<<h.top()<<" ";
        h.pop();
    }

}