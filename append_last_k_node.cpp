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

void append_last_k_node(node* &head, int k)
{
    node* temp = head;
    node* fast = head;
    node* slow = head;

    while(k--)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=head;
    head= slow->next;
    slow->next=NULL;
}

void display(node* head)
{
    node* temp = head;

    int var=20;

    while(temp!=NULL && var--)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    node* head=NULL;
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);

    int k=3;
    append_last_k_node(head,k);
    display(head);


}