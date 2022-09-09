#include "s_linked_list.h"
using namespace std;

int main()
{
    LinkedList<int> *ll = new LinkedList<int>();
    vector<int> example = {1, 2, 3, 4, 5, 6};
    cout << "Example array is the following:" << endl;
    copy(example.begin(), example.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for (auto &&s : example)
    {
        ll->insert(s);
    }
    cout << "Array that is being out from the traversed is:" << endl;
    ll->display();
    cout << endl;
}
