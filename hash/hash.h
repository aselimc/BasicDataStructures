#include <bits/stdc++.h>
using namespace std;

template <typename type>
class Hash
{
protected:
    struct Node
    {
        type data;
        Node *next;
    };
    Node **table;
    int size;
    int hashFunction(type);

public:
    Hash(int);
    ~Hash();
    void insert(type);
    void remove(type);
    bool search(type);
    void display();
};

template <typename type>
Hash<type>::Hash(int size)
{
    this->size = size;
    table = new Node *[size];
    for (int i = 0; i < size; i++)
        table[i] = NULL;
}

template <typename type>
Hash<type>::~Hash()
{
    for (int i = 0; i < size; i++)
    {
        Node *temp = table[i];
        while (temp != NULL)
        {
            Node *del = temp;
            temp = temp->next;
            delete del;
        }
    }
    delete[] table;
}

template <typename type>
int Hash<type>::hashFunction(type data)
{
    return data % size;
}

template <typename type>
void Hash<type>::insert(type data)
{
    int index = hashFunction(data);
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (table[index] == NULL)
        table[index] = newNode;
    else
    {
        Node *temp = table[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

template <typename type>
void Hash<type>::remove(type data)
{
    int index = hashFunction(data);
    Node *temp = table[index];
    if (temp == NULL)
        return;
    if (temp->data == data)
    {
        table[index] = temp->next;
        delete temp;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            Node *del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}

template <typename type>
bool Hash<type>::search(type data)
{
    int index = hashFunction(data);
    Node *temp = table[index];
    while (temp != NULL)
    {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}

template <typename type>
void Hash<type>::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << i << ": ";
        Node *temp = table[i];
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
