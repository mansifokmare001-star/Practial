#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    cout << "Node inserted successfully.\n";
}

// Delete at beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;

    cout << "Node deleted successfully.\n";
}

// Forward traversal
void displayForward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Forward Traversal: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Backward traversal
void displayBackward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    // Move to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "Backward Traversal: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

// Main function
int main()
{
    int choice, value;

    do
    {
        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Forward Traversal\n";
        cout << "4. Backward Traversal\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                deleteAtBeginning();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}