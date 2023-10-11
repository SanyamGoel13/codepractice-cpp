#include<iostream>
using namespace std;
class node
{
    //properties
    public:
    int data;
    node* next;
    //functions
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertathead(node*& head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
    }
    else
    {
        node* a=head;
        head=new node(d);
        head->next=a;
    }
}
int size_linklist(node*head)
{
    int count=1;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
void insertattail(node*&head,int d)
{
    if(head==NULL)
    {
        insertathead(head,d);
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new node(d);
    }
}
void insertatmiddle(node*& head,int pos,int d)
{
    if(head==NULL || pos==0)
    {
        head=new node(d);
    }
    else if(pos>size_linklist(head))
    {
        insertattail(head,d);
    }
    else
    {
        node*temp=head;
        int count=1;
        while(count<pos)
        {
            temp=temp->next;
            count++;
        }
        node*n=temp->next;
        temp->next=new node(d);
        temp->next->next=n;
    }
}
void takevalue(node*& head)
{
    int n;
    while(cin>>n)
    {
        insertathead(head,n);
    }
}
void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
void reverselinklist(node*&head)
{
    node*prev=NULL;
    node*c=head;
    node*n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=prev;
        prev=c;
        c=n;
    }
    head=prev;
}
void recursivereverselinklist(node*&head,node*curr,node*prev=NULL)
{
    if(curr==NULL)
    {
        head=prev;
        return;
    }
    node*n=curr->next;
    curr->next=prev;
    recursivereverselinklist(head,n,curr);

}
void midpointoflinklist(node* head)
{
    node* s=head;
    node* f=head->next;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
    } 
    cout<<s->data;

}
void kthfromlast(node*head,int k)
{
    node*s=head;
    node*f=head;
    int count=0;
    while(f!=NULL)
    {
        if(count<=k)
        {
            count++;
            f=f->next;
        }
        else
        {
            f=f->next;
            s=s->next;
        }
    }
    s=s->next;
    cout<<s->data;
}
node* sorttwosortedlist(node*a,node*b)
{
    //base case
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    //one solved case
    node*c =NULL;
    if(a->data < b->data)
    {
        c=a;
        c->next=sorttwosortedlist(a->next,b);
    }
    else
    {
        c=b;
        c->next=sorttwosortedlist(a,b->next);
    }
    return c;
}
int main()
{
    node* head=NULL;
    //node*head1=NULL;
    takevalue(head);
    //takevalue(head1);
   /*insertathead(head,3);
    insertathead(head,5);
    insertathead(head,4);
    insertathead(head,7);
    print(head);
    cout<<endl;
    insertatmiddle(head,2,1);
    insertatmiddle(head,3,9);
    print(head);
    cout<<endl;
    insertattail(head,6);*/
    /*print(head);
    cout<<endl;
    reverselinklist(head);
    print(head);
    recursivereverselinklist(head,head);
    cout<<endl;
    print(head);
    cout<<endl;
    midpointoflinklist(head);
    cout<<endl;
    kthfromlast(head,3);*/
    node*c;
    c=sorttwosortedlist(head,head1);
    print(head);
}