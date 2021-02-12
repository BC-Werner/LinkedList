#include "../include/LinkedList.h"

using namespace std;

int main() {

    // Create a new List
    LinkedList LL;

    cout << "--Input into the Linked List--" << endl;
    for (int i = 0; i < 10; i++) {
        if (i > 5) {
            int x = i - (i % 5);
            LL.insertTail(x);
        } else {
            LL.insertTail(i);
        }
    }

    // Print the List to the console
    LL.printList();

    cout << "\n--Removing from the List--" << endl;
    // Remove from the List
    LL.removeHead();
    LL.removeIndex(2);
    LL.removeTail();
    LL.printList();

    cout << "\n--Getting data from an index in the List--" << endl;
    // Get the data from an Index in the List
    // --can also use .getHead() or .getTail()
    int data = LL.getIndex(1)->getData();
    cout << "Index 1 contains the data: {- " << data << " -}" << endl;

    // Searching the List for the given value
    cout << "\n--Searching for data in the List--" << endl;
    vector<int> searchData = LL.search(5);

    cout << "Value: 5 was found at index {- ";
    for (auto it : searchData)
        cout << it << " ";
    cout << "-}" << endl;
    
    // Repopulating the List
    cout << "\n--Inserting into the list with a for-loop--" << endl;
    LL.clearList();
    for (int i = 1; i < 6; i++) {
        LL.insertIndex(i, i);
    }
    LL.printList();
    
    // Reverse the List in place
    cout << "\n--Reversing the List--" << endl;
    LL.reverseList();

    // Change the data at a location [i] and at the head and tail
    cout << "\n--Changing the data at an index in the List--" << endl;
    LL.setHead(6);
    LL.setIndex(4, 2);
    LL.setIndex(9, 1);
    LL.setTail(0);
    LL.printList();

    // Searching the List for the given value
    cout << "\n--Searching for data in the List--" << endl;
    searchData = LL.search(6);

    cout << "Value: 6 was found at index {- ";
    for (auto it : searchData)
        cout << it << " ";
    cout << "-}" << endl;
    
    // Empty the List
    LL.clearList();
    return 0;
}
