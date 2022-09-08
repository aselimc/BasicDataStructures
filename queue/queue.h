#include <bits/stdc++.h>
using namespace std;


template <typename type>
class Queue
{
    protected:
    struct Node
    {
        type data;
        Node *next;
    };
    Node *front, *rear;
    int size;

    public:
    Queue();
    ~Queue();
    void enqueue(type);
    type dequeue();
    type peek();

    bool isEmpty();
    int getSize();
};

template <typename type>
Queue<type>::Queue()
{
    front = rear = NULL;
    size = 0;
}

template <typename type>
Queue<type>::~Queue()
{
    while (!isEmpty())
        dequeue();
}

template <typename type>
void Queue<type>::enqueue(type data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename type>
type Queue<type>::dequeue()
{
    if (isEmpty())
        throw "Queue is empty";

    Node *temp = front;
    type data = temp->data;
    front = front->next;
    delete temp;
    size--;
    return data;
}

template <typename type>
type Queue<type>::peek()
{
    if (isEmpty())
        throw "Queue is empty";
    return front->data;
}

template <typename type>
bool Queue<type>::isEmpty()
{
    return front == NULL;
}

template <typename type>
int Queue<type>::getSize()
{
    return size;
}


