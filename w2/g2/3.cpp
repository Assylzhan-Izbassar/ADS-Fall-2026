#include <iostream>

using namespace std;

class Node {
public:
    int x;
    Node* next;

    Node(int x) : x(x), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr) {}

    void push_back(int x) {
        if (!head) {
            tail = new Node(x);
            head = tail;
        } else {
            // Node* copyHead = head;
            // while (copyHead->next != nullptr) {
            //     copyHead = copyHead->next;
            // }
            // copyHead->next = new Node(x);
            tail->next = new Node(x);
            tail = tail->next;
        }
    }

    Node* reverse(Node* currNode) {
        if (currNode->next == nullptr) {
            return currNode;
        }
        Node* newHead = reverse(currNode->next);
        currNode->next->next = currNode;
        currNode->next = nullptr;
        return newHead;
    }

    void print() {
        Node* copyHead = head;
        while (copyHead != nullptr) {
            cout << copyHead->x;
            if (copyHead -> next != nullptr) {
                cout << " -> ";
            }
            copyHead = copyHead -> next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList* ll = new LinkedList();

    ll->push_back(10);
    ll->push_back(15);
    ll->push_back(7);
    ll->push_back(12);

    ll->print();

    Node* reversedHead = ll->reverse(ll->head);

    Node* copyHead = reversedHead;
    while (copyHead != nullptr) {
        cout << copyHead->x;
        if (copyHead -> next != nullptr) {
            cout << " -> ";
        }
        copyHead = copyHead -> next;
    }
    cout << endl;

    return 0;
}