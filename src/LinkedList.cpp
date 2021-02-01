#include "../include/LinkedList.h"

LinkedList::LinkedList() {
    this->head = NULL;
    this->size = 0;
};

void LinkedList::insertHead(int data) {
    if (this->head == NULL) {
        Node *node = new Node(data);
        this->head = node;
        this->size++;
    } else {
        Node *node = new Node(data);
        node->setNext(this->head);
        this->head = node;
        this->size++;
    }
};

void LinkedList::insertTail(int data) {
    if (this->head == NULL) {
        this->insertHead(data);
    } else {
        Node *node = new Node(data);
        Node *current = this->head;

        while (current->getNext() != NULL) {
            current = current->getNext();
        }

        current->setNext(node);
        this->size++;
    }
};

void LinkedList::insertIndex(int data, int index) {
    if (index >= this->size) {
        this->insertTail(data);
        return;
    }
    if (index <= 0) {
        this->insertHead(data);
        return;
    }
    if (index > 0 && index < this->size) {
       Node *node = new Node(data);
       Node *current = this->head;
       Node *prev = NULL;
       int count = 0;

       while (count < index) {
           prev = current;
           current = current->getNext();
           count++;
       } 

        prev->setNext(node);
        node->setNext(current);
        this->size++;
    }
}

void LinkedList::removeHead() {
    if (this->head != NULL) {
        Node *temp = this->head;
        this->head = this->head->getNext();
        this->size--;

        delete temp;
    }
}

void LinkedList::removeTail() {
    if (this->head != NULL) {
        Node *current = this->head;
        Node *prev = NULL;

        while (current->getNext() != NULL) {
            prev = current;
            current = current->getNext();
        }

        prev->setNext(NULL);
        this->size--;

        delete current;
    }
}

void LinkedList::removeIndex(int index) {
    if (index >= this->size) {
        this->removeTail();
        return;
    }
    if (index <= 0) {
        this->removeHead();
        return;
    }
    if (index > 0 && index < this->size) {
        Node *current = this->head;
        Node *prev = NULL;
        int count = 0;

        while (count < index) {
            prev = current;
            current = current->getNext();
            count++;
        }

        prev->setNext(current->getNext());
        this->size--;

        delete current;
    }
}

Node* LinkedList::getHead() {
    return this->head;
}


Node* LinkedList::getTail() {
    if (this->head != NULL) {
        Node *current = this->head;

        while (current->getNext() != NULL) {
            current = current->getNext();
        }

        return current;
    }

    return NULL;
}

Node* LinkedList::getIndex(int index) {
    if (index >= this->size) return this->getTail();
    if (index <= 0) return this->getHead();
    if (this->head != NULL) {
        Node *current = this->head;
        int count = 0;

        while (count < index)
        {
            current = current->getNext();
            count++;
        }
        
        return current;
    }

    return NULL;
}

int LinkedList::getSize() {
    return this->size;
}

void LinkedList::clearList() {
    if (this->head != NULL) {
        Node *current = this->head;
        Node *prev = NULL;

        while(current->getNext() != NULL) {
            prev = current;
            current = current->getNext();
            this->size--;

            delete prev;
        }

        this->size--;

        delete current;
        this->head = NULL;
    }
}

void LinkedList::printList() {
    if (this->head == NULL) {
        cout << "Empty List" << endl;
    } else {
        Node *current = this->head;

        cout << "{- ";

        while (current->getNext() != NULL) {
            cout << current->getData() << " ";
            current = current->getNext();
        }

        cout << current->getData() << " -}" << endl;
    }
};


void LinkedList::reverseList() {
    // Copy the list into a temporary list
    LinkedList tempLL;
    Node *current = this->head;

    while (current->getNext() != NULL) {
        tempLL.insertHead(current->getData());
        current = current->getNext();
    } 

    tempLL.insertHead(current->getData());

    // Clear the currentent list
    this->clearList();

    // Copy the temporary list into the original list
    current = tempLL.head;

    while (current->getNext() != NULL)
    {
        this->insertTail(current->getData());
        current = current->getNext();
    }

    this->insertTail(current->getData());

    this->printList();

    // Clear the temporary list
    tempLL.clearList();
}

    
