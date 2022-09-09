#include "d_linked_list.h"
using namespace std;

int main()
{   
    LinkedList<int>* ll = new LinkedList<int> ();
    vector<int> example = {1,2,3,4,5,6};
    cout << "Example array is the following:" << endl;
    copy(example.begin(), example.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    for (auto&& s: example){
        ll->push(s, 0, "back");
    }
    cout << "Array that is being out from the traversed is:" << endl;
    vector<int> traversed = ll->traverse_to_vector();
    copy(traversed.begin(), traversed.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}