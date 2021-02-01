#include "Node.h"

class LinkedList {
    private:
        Node *head;
        int size;

    public:
        LinkedList();

        void insertHead(int data);
        void insertTail(int data);
        void insertIndex(int data, int index);
        void removeHead();
        void removeTail();
        void removeIndex(int index);
        Node *getHead();
        Node *getTail();
        Node *getIndex(int index);
        int getSize();
        void clearList();
        void printList();
        void reverseList();
};
