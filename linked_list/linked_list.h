#include <bits/stdc++.h>
using namespace std;

template <typename type>
class LinkedList
{
protected:
    struct Node
    {
        type val;
        Node *next;
        Node *prev;
        Node() : val(0), next(nullptr), prev(nullptr) {}
        Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    };

public:
    const type getItemAt(int pos) const;
    void push(const type &value, int pos, string position);
    void pushBack(const type &value);
    void pushFront(const type &value);
    void pushAt(const type &value, int pos);
    type pop(int pos = 0, string position = "back");
    type popBack();
    type popFront();
    type popAt(int pos);
    const int getSize() const;
    vector<type> traverse_to_vector();

private:
    Node *head_;
    Node *tail_;
    int size_;

public:
    Node *getNodeAt(int pos)
    {
        Node *node = nullptr;
        if (pos < size_ / 2)
        {
            while (pos--)
                head_ = head_->next;
            return head_;
        }
        else
        {
            int size = size_ - pos - 1;
            while (size--)
                tail_ = tail_->prev;
            return tail_;
        }
    };
};
template <typename type>
void LinkedList<type>::push(const type &value, int pos, string position)
{
    if (position == "back")
        pushBack(value);
    else if (position == "front")
        pushFront(value);
    else if (position == "insert")
        pushAt(value, pos);
    else
        throw invalid_argument("Wrong position type entered. Available position types are: back, front, insert");
}

template <typename type>
void LinkedList<type>::pushBack(const type &value)
{
    Node *node = new Node(value);
    if (!head_)
    {
        head_ = node;
        tail_ = node;
    }
    else
    {
        tail_->next = node;
        node->prev = tail_;
        tail_ = node;
    }
    size_++;
}

template <typename type>
void LinkedList<type>::pushFront(const type &value)
{
    Node *node = new Node(value);
    if (!head_)
    {
        head_ = node;
        tail_ = node;
    }
    else
    {
        head_->prev = node;
        node->next = head_;
        head_ = node;
    }
    size_++;
}

template <typename type>
void LinkedList<type>::pushAt(const type &value, int pos)
{
    Node *node = new Node(value);
    if (!head_)
    {
        head_ = node;
        tail_ = node;
    }
    else if ((pos - size_) < 0)
    {
        throw invalid_argument("Index exceeds linked list size");
    }
    else if (pos == 0)
    {
        pushFront(value);
    }
    else if (pos == size_)
    {
        pushBack(value);
    }
    else
    {
        Node *node = new Node(value);
        Node *current = getNodeAt(pos);
        Node *prev_current = current->prev;
        node->next = current;
        node->prev = current->prev;
        current->prev = node;
        prev_current->next = node;
    }
    size_++;
}

template <typename type>
type LinkedList<type>::pop(int pos, string position)
{
    if (position == "back")
        return popBack();
    else if (position == "front")
        return popFront();
    else if (position == "insert")
        return popAt(pos);
    else
        throw invalid_argument("Wrong position type entered. Available position types are: back, front, insert");
}

template <typename type>
type LinkedList<type>::popBack()
{
    if (!head_)
        throw("LinkedList is empty");
    else if (size_ == 1)
    {
        type value = tail_->val;
        head_ = nullptr;
        tail_ = nullptr;
        return value;
    }
    else
    {
        type value = tail_->val;
        tail_->prev->next = nullptr;
        tail_ = tail_->prev;
        size_--;
        return value;
    }
}

template <typename type>
type LinkedList<type>::popFront()
{
    if (!head_)
        throw("LinkedList is empty");
    else if (size_ == 1)
    {   
        type value = tail_->val;
        head_ = nullptr;
        tail_ = nullptr;
        return value;
    }
    else
    {
        type value = head_->val;
        head_->next->prev = nullptr;
        head_ = head_->next;
        size_--;
        return value;
    }
}

template <typename type>
type LinkedList<type>::popAt(int pos)
{
    if (!head_)
        throw("LinkedList is empty");
    else
    {
        Node *current = getNodeAt(pos);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        size_--;
        return current->val;
    }
}

template <typename type>
const int LinkedList<type>::getSize() const
{
    return size_;
}

template <typename type>
vector<type> LinkedList<type>::traverse_to_vector()
{
    Node* traverser = head_;
    vector<type> output;
    while(traverser != nullptr)
    {
        output.push_back(traverser->val);
        traverser = traverser->next;
    }
    return output;
}