#include "stack.h"
using namespace std;

int main()
{
    Stack<int> *stack = new Stack<int>();
    vector<int> example = {1, 2, 3, 4, 5, 6};
    cout << "Example array is the following:" << endl;
    copy(example.begin(), example.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for (auto &&s : example)
    {
        stack->push(s);
    }
    cout << "Array that is being out from the traversed is:" << endl;
    vector<int> traversed;
    while (!stack->isEmpty())
    {
        traversed.push_back(stack->pop());
    }
    copy(traversed.begin(), traversed.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}