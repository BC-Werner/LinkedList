#include "../include/LinkedList.h"

int main() {

    // Create a new List
    LinkedList LL;

    cout << "--Input into the Linked List--" << endl;
    // Input into the List
    LL.insertHead(1);
    LL.insertIndex(2, 1);
    LL.insertIndex(3, 2);
    LL.insertIndex(4, 3);
    LL.insertTail(5);

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
    cout << "{- " << data << " -}" << endl;

    // Searching the List for the given value
    cout << "\n--Searching for data in the List--" << endl;
    LL.search(4);

    
    cout << "\n--Inserting into the list with a for-loop--" << endl;
    // Repopulating the List
    LL.clearList();
    for (int i = 1; i < 6; i++) {
        LL.insertIndex(i, i);
    }
    LL.printList();
    
    cout << "\n--Reversing the List--" << endl;
    // Reverse the List in place
    LL.reverseList();

    cout << "\n--Changing the data at an index in the List--" << endl;
    // Change the data at a location [i] and at the head and tail
    LL.setHead(6);
    LL.setIndex(4, 2);
    LL.setIndex(9, 1);
    LL.setTail(0);
    LL.printList();

        // Searching the List for the given value
    cout << "\n--Searching for data in the List--" << endl;
    LL.search(4);

    
    // Empty the List
    LL.clearList();
    return 0;
}
