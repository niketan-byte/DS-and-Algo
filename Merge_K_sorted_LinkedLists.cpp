#include <iostream>

class Node
{
public:
    int data;
    Node *next = NULL;
};

class LinkedList
{
public:
    Node *head = NULL, *tail = NULL;
    LinkedList(int *arr = NULL, int n = 0, Node *h = NULL)
    {
        if (h)
            head = h;
        for (int i = 0; i < n; i++)
            insert(arr[i]);
    }

    insert(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        if (head == NULL)
            head = temp;
        else
            tail->next = temp;
        tail = temp;
    }

    print()
    {
        for (Node *ref = head; ref; ref = ref->next)
            std::cout << ref->data << " -> ";
        std::cout << "NULL"<< std::endl;
    }
};

Node *merge_sorted(Node *L1, Node *L2)
{
    if (L1 == NULL)
        return L2;
    if (L2 == NULL)
        return L1;

    Node *head;
    if (L1->data > L2->data)
        head = L2,
        L2 = L2->next;

    else
        head = L1,
        L1 = L1->next;

    Node *ref = head;
    while (L1 && L2)
    {
        if (L1->data > L2->data)
            ref->next = L2,
            L2 = L2->next;
        else
            ref->next = L1,
            L1 = L1->next;
        ref = ref->next;
    }
    ref->next = L2 ? L2 : L1;
    return head;
}

main()
{
    int items[] = {1, 2, 4, 5, 9};
    LinkedList L1 = LinkedList(items, 5);
    int items2[] = {1, 4, 9, 7, 11};
    LinkedList L2 = LinkedList(items2, 5);
    LinkedList(NULL, 0, merge_sorted(L1.head, L2.head)).print();
}