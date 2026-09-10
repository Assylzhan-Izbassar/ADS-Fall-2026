#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

    Node* reverseRec(Node* currNode) {
        if (currNode->next == nullptr) {
            return currNode;
        }
        Node* newHead = reverseRec(currNode->next);
        currNode->next->next = currNode;
        currNode->next = nullptr;
        return newHead;
    }
public:
    LinkedList(): head(nullptr) {}

    void push_back(int data) {
        if (head == nullptr) {
            tail = new Node(data);
            head = tail;
        } else {
            tail->next = new Node(data);
            tail = tail->next;
        }
    }

    void reverse() {
        head = reverseRec(head);
    }

    void print() {
        Node* currNode = head;

        while (currNode != nullptr) {
            cout << currNode->data;
            if (currNode->next != nullptr) {
                cout << "->";
            }
            currNode = currNode->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList* ll = new LinkedList();

    ll->push_back(12);
    ll->push_back(34);
    ll->push_back(74);
    ll->push_back(100);

    ll->print();

    ll->reverse();

    ll->print();

    return 0;
}