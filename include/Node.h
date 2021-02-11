#include <iostream>

class Node {
    private:
        int data;
        Node *next;

    public:
        Node(int data, Node *next = NULL) {
            this->data = data;
            this->next = next;
        }

        int getData() { return data; }
        Node *getNext() { return next; }
        void setData(int data) { this->data = data; }
        void setNext(Node *next) { this->next = next; }
};
