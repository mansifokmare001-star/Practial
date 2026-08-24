#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        cout << value << " inserted" << endl;
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << queue[front] << " deleted" << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    enqueue(40);
    enqueue(50);

    return 0;
}