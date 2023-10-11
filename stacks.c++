//implementation of stack
#include<iostream>
#include<stack>
using namespace std;
class Stack
{   
    //properties
    public:
    int *arr;
    int top;
    int size;
    // behaviour
    Stack(int size)
    {
        this -> size=size;
        top=-1;
        arr= new int(size);
    }
    void push(int element)
    {
         if(size-top>1)
         {
            top++;
            arr[top]=element;
         }
         else
         {
            cout << "stack is overflow" << endl;
         }
         
    }
    void pop()
    {
        if( top >=0 )
        {
            top--;
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }
    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            return -1;
        }
    }
    bool IsEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
int main()
{
    Stack st(6);
    st.push(3);
    st.push(6);
    st.push(5);
    st.push(2);
    st.push(4);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    if(st.IsEmpty())
    cout << "yes, stack is empty" << endl;
    else
    cout << "no, stack is not empty" << endl;


}
