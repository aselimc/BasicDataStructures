#include "queue.h"
using namespace std;

int main()
{
    Queue<int> *q = new Queue<int>();
    vector<int> example = {1, 2, 3, 4, 5, 6};
    cout << "Example array is the following:" << endl;
    copy(example.begin(), example.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for (auto &&s : example)
    {
        q->enqueue(s);
    }
    cout << "Array that is being out from the traversed is:" << endl;
    vector<int> traversed;
    while (!q->isEmpty())
    {
        traversed.push_back(q->dequeue());
    }
    copy(traversed.begin(), traversed.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}