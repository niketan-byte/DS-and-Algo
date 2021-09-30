#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head, int val)
{
    node* temp = new node(val);
    if(head==NULL)
    {
        head= temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void even_odd(node* head)
{
    node* temp = head;
    node* oh = head;
    node* eh = oh->next;
    node* even = eh;
    node* odd = oh;

    temp=temp->next->next;
    int i=1;
    while(temp!=NULL)
    {
        if(i%2==1)
        {
            odd->next=temp;
            odd=temp;
            temp=temp->next;
        }
        else
        {
            even->next=temp;
            even=temp;
            temp=temp->next;
        }
        i++;
    }
    odd->next=eh;
}

void display(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    node* head=NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    // insertAtHead(head, 7);
    display(head);

    even_odd(head);
    display(head);
}