#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void insert(T data);
    void insertAt(int index, T data);
    void display();
    void remove(T data);
    void removeAt(int index);
    int getSize();
    bool isEmpty();
    bool search(T data);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (!isEmpty())
        removeAt(0);
}

template <typename T>
void LinkedList<T>::insert(T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    size++;
}

template <typename T>
void LinkedList<T>::insertAt(int index, T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (index == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *temp1 = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
    size++;
}

template <typename T>
void LinkedList<T>::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (prev == NULL)
            {
                head = temp->next;
                delete temp;
                size--;
                return;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                size--;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
    Node *temp = head;
    Node *prev = NULL;
    for (int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        head = temp->next;
        delete temp;
        size--;
        return;
    }
    else
    {
        prev->next = temp->next;
        delete temp;
        size--;
        return;
    }
}

template <typename T>
int LinkedList<T>::getSize()
{
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
bool LinkedList<T>::search(T data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
