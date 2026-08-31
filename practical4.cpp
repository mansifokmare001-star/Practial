#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert node at the end
void insert(int value)
{
    Node* newNode = new Node();

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Display the list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    cout << "Circular Singly Linked List: ";

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    while (temp != head);

    cout << "HEAD" << endl;
}

int main()
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        insert(value);
    }

    display();

    return 0;
}