#include <iostream>

class Node {
    private:
        int data;
        Node *next;

    public:
        Node(int data, Node *next = nullptr) : data{data}, next{next} {}
        ~Node() { std::cout << "Deleting Node with data: " << data << std::endl; }

        int getData() { return data; }
        Node *getNext() { return next; }
        void setData(int data) { this->data = data; }
        void setNext(Node *next) { this->next = next; }
};
