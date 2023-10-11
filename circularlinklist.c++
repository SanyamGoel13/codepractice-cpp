#include <iostream>
using namespace std;
class node
{
    // properties
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertathead(node *&head, int d)
{
    {
        node *n = new node(d);
        n->next = head;
        node *temp = head;
        if (temp != NULL)
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        else
        {
            n->next = n;
        }
        head = n;
    }
}
void print(node *head)
{
    node*temp=head;
    while (temp->next != head)
    {
        cout << temp->data<<" ";
        temp= temp->next;
    }
    cout << temp->data;
    return;
}
int main()
{
    node *head = NULL;
    insertathead(head, 10);
    insertathead(head, 20);
    insertathead(head, 30);
    insertathead(head, 40);
    print(head);
}
