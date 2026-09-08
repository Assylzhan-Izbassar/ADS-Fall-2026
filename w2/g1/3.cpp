#include <iostream>

using namespace std;

class Node { // class / struct - access modifier
public:
    int x;
    Node* next;

    Node(int x) : x(x), next(nullptr) {}
};

class LinkedList {
private:
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
    Node* head;

    LinkedList() : head(nullptr) {}

    void push_back(int x) {
        if (!head) {
            head = new Node(x);
        } else {
            Node* copyNode = head;
            while (copyNode->next != nullptr) {
                copyNode = copyNode->next;
            }
            copyNode->next = new Node(x);
        }
    }

    void reverse() {
        head = reverseRec(head);
    }

    void print() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->x;
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

    ll->push_back(54);
    ll->push_back(123);
    ll->push_back(12);
    ll->push_back(44);

    ll->print();

    ll->reverse();

    ll->print();

    return 0;
}