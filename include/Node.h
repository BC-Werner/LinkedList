#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *next;

    public:
        Node(int data, Node *next = NULL) {
            this->data = data;
            this->next = next;
        }

        int getData() {
            return this->data;
        }

        Node *getNext() {
            return this->next;
        }

        void setData(int data) {
            this->data = data;
        }

        void setNext(Node *next) {
            this->next = next;
        }
};
