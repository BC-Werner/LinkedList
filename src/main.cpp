#include "../include/LinkedList.h"

int main() {

    // Create a new List
    LinkedList LL;

    // Input into the List
    LL.insertHead(1);
    LL.insertIndex(2, 1);
    LL.insertIndex(3, 2);
    LL.insertIndex(4, 3);
    LL.insertTail(5);

    // Print the List to the console
    LL.printList();

    // Remove from the List
    LL.removeHead();
    LL.removeIndex(2);
    LL.removeTail();
    LL.printList();

    // Get the data from an Index in the List
    // --can also use .getHead() or .getTail()
    int data = LL.getIndex(1)->getData();

    cout << "{- " << data << " -}" << endl;

    // Repopulating the List
    LL.insertHead(1);
    LL.insertIndex(4, 3);
    LL.insertTail(5);
    LL.printList();

    // Reverse the List in place
    LL.reverseList();

    // Empty the List
    LL.clearList();
    return 0;
}
