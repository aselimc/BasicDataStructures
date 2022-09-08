#include "hash.h"
using namespace std;

int main()
{
    Hash<int> *hash = new Hash<int>(10);
    vector<int> example = {1, 2, 3, 4, 5, 6};
    cout << "Example array is the following:" << endl;
    copy(example.begin(), example.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for (auto &&s : example)
    {
        hash->insert(s);
    }
    cout << "Array that is being out from the traversed is:" << endl;
    hash->display();
    cout << endl;
}
