#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr, head};
    if (head) head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAfter(Node*& head, int pos) {
    Node* temp = head;
    for (int i = 0; temp && i < pos; ++i)
        temp = temp->next;
    if (temp && temp->next) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next) toDelete->next->prev = temp;
        delete toDelete;
    }
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    printList(head);
    
    deleteAfter(head, 1);
    printList(head);
    
    insertAtBeginning(head, 10);
    printList(head);
    
    return 0;
}
