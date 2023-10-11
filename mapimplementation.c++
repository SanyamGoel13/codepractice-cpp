#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class node
{
    //properties
    public:
    string key;
    T value;
    node<T>* next;
    //functions
    node(string key,T val)
    {
        this->key=key;
        value=val;
        next=NULL;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class hashtable
{
    private:
    node<T>** table;
    int table_size;
    int current_size;
    int hashfunction(string key)
    {
        int size=key.size();
        int index=0;
        int p=1;
        for(int i=0;i<size;i++)
        {
            index=index+(key[i]*p)%table_size;
            index=index%table_size;
            p=(p*27)%table_size;
        }
        return index;
    }
    void rehash()
    {
        node<T>** oldtable=table;
        int oldtablesize=table_size;
        table_size=2*table_size;
        table=new node<T>* [table_size];
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
        current_size=0;
        for(int i=0;i<oldtablesize;i++)
        {
            node<T>* temp=oldtable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL)
            {
                delete  oldtable[i];
            }
        }
        delete [] oldtable;
    }
    public:
    hashtable(int ts=7)
    {
        table_size=ts;
        table=new node<T>* [table_size];
        current_size=0;
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
    }
    void insert(string key,T value)
    {
        int index=hashfunction(key);
        node<T>* ans=new node<T>(key,value);
        ans->next=table[index];
        table[index]=ans;
        current_size++;
        float load_factor=current_size/(1.0*table_size);
        if(load_factor>0.7)
        {
            rehash();
        }
    }
    void print()
    {
        for(int i=0;i<table_size;i++)
        {
            cout<<i<<"->"<<" ";
            node<T>* temp=table[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<" "<<temp->value<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string key)
    {
        int index=hashfunction(key);
        node<T>* temp=table[index];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &temp->value;
            }
            temp=temp->next;
        }
        return NULL;
    }

};
int main()
{
    hashtable<int> menu;
    menu.insert("Burger",40);
    menu.insert("pizza",300);
    menu.insert("cake",200);
    menu.insert("momos",30);
    menu.insert("thali",400);
    menu.print();
    int *price=menu.search("Burger");
    //cout<<endl;
    cout<<*price;
}
