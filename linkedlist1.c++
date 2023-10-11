#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
} ;
void insertathead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
    }
    else
    {
        node*temp=head;
        head= new node(d);
        head->next=temp;
        //node*n =new node(d);
        //n->next=head;
        // head=n;
    }
}
void printlinkedlist(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
int length(node*head)
{
    int count=1;
    while(head!= NULL)
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
void insertatmiddle(node*&head, int pos,int d)
{
    if(head==NULL || pos==0)
    {
        head=new node(d);
    }
    else if(pos>length(head))
    {
        insertattail(head,d);
    }
    else
    {
        int jump=1;
        node*temp=head;
        while(jump<=pos-1)
        {
            temp=temp->next;
            jump++;
        }
        /*node*n= new node(d);
        n->next=temp->next;
        temp->next=n;*/
        node*n=temp->next;
        temp->next=new node(d);
        (temp->next)->next=n;
    }
}
void deleteathead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        node*temp=head->next;
        delete(head);
        head=temp;
    }
}
void reverselinklist(node*&head)
{
    node*c=head;
    node*prev=NULL;
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
int main()
{
    node*head = NULL;
    insertathead(head, 6);
    insertathead(head, 4);
    insertathead(head, 7);
    insertathead(head, 5);
    printlinkedlist(head);
    cout<<endl;
    insertatmiddle(head,3,2);
    printlinkedlist(head);
    cout<<endl;
    insertattail(head,9);
    printlinkedlist(head);
    cout<<endl;
    deleteathead(head);
    printlinkedlist(head);
    reverselinklist(head);
    cout<<endl;
    printlinkedlist(head);
    return 0;
}