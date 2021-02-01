#include "../include/LinkedList.h"

int main() {

    LinkedList LL;

    LL.insertHead(5);
    LL.insertHead(25);
    LL.insertTail(35);
    LL.insertTail(55);
    LL.insertIndex(45, 2);
    LL.printList();

    LL.reverseList();
    LL.insertTail(50);
    LL.insertTail(20);
    LL.printList();

    LL.removeHead();
    LL.removeTail();
    LL.printList();

    LL.removeIndex(2);
    LL.printList();

    Node *temp = LL.getTail();
    cout << temp->getData() << endl;

    Node *indexed = LL.getIndex(2);
    cout << indexed->getData() << endl;

    return 0;
}
