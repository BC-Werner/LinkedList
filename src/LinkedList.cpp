#include "../include/LinkedList.h"

// Constructor
LinkedList::LinkedList() {
    this->head = NULL;
    this->size = 0;
};

// Destructor
LinkedList::~LinkedList() {
    this->clearList();
    delete this->head;
}

// Insert a new Node at the beginning of the List
void LinkedList::insertHead(int data) {
    if (this->head == NULL) {
        Node *node = new Node(data);
        this->head = node;
        this->size++;
    } else {
        Node *node = new Node(data, this->head);
        this->head = node;
        this->size++;
    }
};

// Insert a new Node at the end of the List
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

// Insert a new Node at a given index in the List
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

// Delete the Node at the beginning of the List
void LinkedList::removeHead() {
    if (this->head != NULL) {
        Node *temp = this->head;
        this->head = this->head->getNext();
        this->size--;

        delete temp;
    }
}

// Delete the Node at the end of the List
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

// Delete the Node at a given index in the List
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

// Return the Node at the beginning of the List
Node* LinkedList::getHead() {
    return this->head;
}


// Return the Node at the end of the List
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


// Return the Node at a given index in the List
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


// Search the List for a Node with the given data
// returns a Vector containing the indexes where the given data was found
// prints to the console if the List is empty or the given data was not in the List
vector<int> LinkedList::search(int data) {
    vector<int> positions;

    if (this->head == NULL) {
        cout << "The List is empty" << endl;
        return positions;

    } else {

        Node *current = this->head;
        int index = 0;
        bool found = false;

        while (current != NULL) {
           if (current->getData() == data) {
               found = true;
               positions.push_back(index);
           }

           current = current->getNext();
           index++;
        }

        if (!found) cout << "Value: " << data << " :could not be found in the List" << endl;
        return positions;
    }
    
}



// Return the size of the List
int LinkedList::getSize() {
    return this->size;
}


// Change the value of the Node at the beginning of the List
void LinkedList::setHead(int data) {
    if (this->head != NULL) {
        this->head->setData(data);
    } else {
        this->insertHead(data);
    }
}


// Change the value of the Node at the end of the List
void LinkedList::setIndex(int data, int index) {
    if (index <= 0 || this->head == NULL) {
        this->setHead(data);
    }
    if (index >= this->size) {
        this->setTail(data);
    }
    if (index > 0 && index < this->size) {
        Node *current = this->head;
        int count = 0;

        while (count < index) {
            current = current->getNext();
            count++;
        }

        current->setData(data);
    }
}


// Change the value of the Node at a given index in the List
void LinkedList::setTail(int data) {
    if (this->head != NULL) {
        Node *current = this->head;

        while (current->getNext() != NULL) {
            current = current->getNext();
        }

        current->setData(data);

    } else {
        this->insertTail(data);
    }
}


// Delete all Nodes in the List
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


// Print the List to the console
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


// Reverse the List
void LinkedList::reverseList() {
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->getNext();

        // Reverse current node's pointer
        current->setNext(prev); 

        // Move pointers on position ahead
        prev = current;
        current = next;
    }
    this->head = prev;

    this->printList();
};
