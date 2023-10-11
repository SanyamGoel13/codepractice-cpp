//runtime error
#include<iostream>
using namespace std;
class node
{
    //properties
    public:
    int data;
    node* next;
    //constructor
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertathead(node*&,int);
void insertatend(node*& head,int d)
{
    if(head==NULL)
    {
        insertathead(head,d);
        return;
    }
    node*temp=head;
    for(;temp->next!=NULL;)
    {
        temp=temp->next;
    }
    temp->next=new node(d);
}

void insertathead(node*& head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node*temp=head;
    head=new node(d);
    head->next=temp;
}
int sizeoflinklist(node*head)
{
    int i=0;
    for(;head!=NULL;)
    {
        i++;
        head=head->next;
    }
    //i++;
    return i;
}
void insertatanypos(node*&head,int pos,int d)
{
    if(head==NULL || pos==0)
    {
        insertathead(head,d);
        return;
    }
    if(pos>sizeoflinklist(head))
    {
        insertatend(head,d);
        return;
    }
    int i=1;
    node*temp=head;
    for(;i<pos-1;)
    {
        temp=temp->next;
        i++;
    }
    node*n=temp->next;
    temp->next=new node(d);
    temp->next->next=n;

}
void printlinklist(node*head)
{
    int i;
    for(;head!=NULL;)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
node* reverselinklist(node *head,node*p=NULL)
{
    if(head==NULL)
    {
        head=p;
        return head;
    }
    if(head->next==NULL)
    {
        head->next=p;
        return head;
    }
    node*c=head;
    node*n=head->next;
    node*temp=n->next;
    n->next=c;
    c->next=p;
    reverselinklist(temp,n);
}
node* sum(node*head1,node*head2)
{
    int b=sizeoflinklist(head1);
    int c=sizeoflinklist(head2);
    node*head=NULL;
    int z=0;
    //head->next=new node(6);
    int h=head1->data+head2->data;
        int a=0;
        if(h>9)
        {
            h=h%10;
            a=1;
        }
    node*temp=new node(h);
    head=temp;
    for(;head1->next!=NULL && head2->next!=NULL;)
    {
        z++;
        head1=head1->next;
        head2=head2->next;
        h=head1->data+head2->data;
        int g=h;
        if(h>9)
        {
            h=h%10;
        }
        if(h+a>9)
        {
            temp->next=new node(0);

        }
        else
        {
        //cout<<h+a;
        //cout<<endl;
        temp->next=new node(h+a);
        }
        temp=temp->next; 
        if(g>9 ||g+a>9)
        {
            a=1;
        }
        else
        {
            a=0;
        }
    }
    if(b!=c && a==1)
    {
        if(b>c)
        {
            temp->next=head1->next;
            if(temp->next->data ==9){
            for(;temp->next->data==9;)
            {
                z++;
                temp->next->data=0;
                if(z==b-1)
                {
                    break;
                }
                temp=temp->next;
                
                }
                if(z==b-1)
                {
                    temp=temp->next;
                    temp->next=new node(1);
                }
                else{
            temp->next->data=temp->next->data+1;}}
            else
            {
                temp->next->data=temp->next->data+1;
            }

    
        }
        else
        {
            /*temp->next=head2->next;
            //temp->next->data=temp->next->data+a;
            for(;temp->next->data>8;)
            {
                temp->next->data=0;
                temp=temp->next;
            }
            temp->next->data=temp->next->data+1;*/
            temp->next=head2->next;
            if(temp->next->data >8){
            for(;temp->next->data>8;)
            {
                temp->next->data=0;
                temp=temp->next;
            }
            temp->next->data=temp->next->data+1;}
            else
            {
                temp->next->data=temp->next->data+1;
            }
        }
    }
    else if(b!=c)
    {
        if(b>c)
        {
            temp->next=head1->next;
           // temp->next->data=temp->next->data+a;
        }
        else
        {
            temp->next=head2->next;
            //temp->next->data=temp->next->data+a;
        }
    }
    else if(a==1)
    {
        temp->next=new node(a);
    }
    return head;
}
int main()
{
    node*head1=NULL;
    node*head2=NULL;
    insertathead(head1,8);
    insertathead(head1,9);
    insertathead(head1,9);
    insertathead(head1,9);
    insertathead(head1,9);
    insertathead(head1,9);
    insertathead(head1,9);
    printlinklist(head1);
    cout<<endl;
    //cout<<sizeoflinklist(head1)<<endl;
    //insertatend(head1,2);
    //printlinklist(head1);
    //cout<<endl;
    //insertathead(head2,3);
    /*insertathead(head2,8);
    insertathead(head2,4);
    insertathead(head2,8);
    insertathead(head2,1);
    insertathead(head2,0);*/
    insertathead(head2,9);
    insertathead(head2,9);
    insertathead(head2,9);
    insertathead(head2,9);
    printlinklist(head2);
    cout<<endl;
    //insertatanypos(head,4,1);
    //printlinklist(head);
    node*head=sum(head1,head2);
    printlinklist(head);
    cout<<endl;
    head=reverselinklist(head);
    //cout<<endl;
    printlinklist(head);
    cout<<endl;
    
    

}
