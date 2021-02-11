#include "Node.h"
#include <vector>

class LinkedList {
    private:
        Node *head;
        int size;

    public:
        LinkedList();
        ~LinkedList();

        void insertHead(int data);
        void insertTail(int data);
        void insertIndex(int data, int index);
        void removeHead();
        void removeTail();
        void removeIndex(int index);
        Node *getHead();
        Node *getTail();
        Node *getIndex(int index);
        std::vector<int> search(int data);
        int getSize();
        void setHead(int data);
        void setIndex(int data, int index);
        void setTail(int data);
        void clearList();
        void printList();
        void reverseList();
};
