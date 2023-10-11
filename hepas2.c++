#include <iostream>
#include <vector>
using namespace std;
class heap
{
private:
    vector<int> v;
    bool min_heap;
    bool compare(int index, int parent)
    {
        if (min_heap)
        {
            return v[parent] > v[index];
        }
        return v[parent] < v[index];
    }
    void heapify(int index)
    {
        int left = 2 * index;
        int right = left + 1;
        int req_index = index;
        if (left <= (v.size() - 1) && compare(left, req_index))
        {
            req_index = left;
        }
        if (right <= (v.size() - 1) && compare(right, req_index))
        {
            req_index = right;
        }
        if (req_index != index)
        {
            swap(v[index], v[req_index]);
            heapify(req_index);
        }
    }

public:
    heap(int size = 10, bool how = true)
    {
        v.reserve(size + 1);
        v.push_back(-1);
        min_heap = how;
    }
    void push(int d)
    {
        v.push_back(d);
        int index = v.size() - 1;
        int parent = index / 2;
        while (index > 1 && compare(index, parent))
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }
};
bool compare(int index, int parent, vector<int> v, bool min_heap = true)
{
    if (min_heap)
    {
        return v[parent] > v[index];
    }
    return v[parent] < v[index];
}
void heapify(int index,vector<int>&v,int size)
{
    int left = 2 * index;
    int right = left + 1;
    int req_index = index;
    if (left <= (size - 1) && compare(left, req_index,v,false))
    {
        req_index = left;
    }
    if (right <= (size - 1) && compare(right, req_index,v,false))
    {
        req_index = right;
    }
    if (req_index != index)
    {
        swap(v[index], v[req_index]);
        heapify(req_index,v,size);
    }
}
void buildheap(vector<int> &vec)
{
    int size = vec.size();
    for (int i = 2; i <= size; i++)
    {
        int index = i;
        int parent = i / 2;
        while (index > 1 && compare(index, parent, vec, false))
        {
            swap(vec[index], vec[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
}
void buildheapoptimised(vector<int> &vec)
{
    int size = vec.size() - 1;
    for (int i = size / 2; i >= 1; i--)
    {
        heapify(i, vec,size);
    }
}
void heapsort(vector<int>& vec)
{
    int size = vec.size() ;
    for (int i = size / 2; i >= 1; i--)
    {
        heapify(i, vec,size);
    }
    while(size>1)
    {
        swap(vec[1],vec[size-1]);
        size=size-1;
        heapify(1,vec,size);
    }
}
int main()
{

    int n;
    cin >> n;
    heap h(n);
    for (int i = 1; i <= n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    vector<int> vec{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    buildheapoptimised(vec);
    cout<<endl;
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout<<endl;
    heapsort(vec);
    for (int x : vec)
    {
        cout << x << " ";
    }
}