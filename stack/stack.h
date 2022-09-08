#include <bits/stdc++.h>
using namespace std;

template <typename type>
class Stack
{
protected:
    struct Node
    {
        type data;
        Node *next;
    };
    Node *top;
    int size;

public:
    Stack();
    ~Stack();
    void push(type);
    type pop();
    type peek();

    bool isEmpty();
    int getSize();
};

template <typename type>
Stack<type>::Stack()
{
    top = NULL;
    size = 0;
}

template <typename type>
Stack<type>::~Stack()
{
    while (!isEmpty())
        pop();
}   

template <typename type>
void Stack<type>::push(type data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
        top = newNode;
    else
    {
        newNode->next = top;
        top = newNode;
    }
    size++;
}

template <typename type>
type Stack<type>::pop()
{
    if (isEmpty())
        throw "Stack is empty";
    else
    {
        Node *temp = top;
        type data = temp->data;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
}

template <typename type>
type Stack<type>::peek()
{
    if (isEmpty())
        throw "Stack is empty";
    else
        return top->data;
}

template <typename type>
bool Stack<type>::isEmpty()
{
    return top == NULL;
}

template <typename type>
int Stack<type>::getSize()
{
    return size;
}