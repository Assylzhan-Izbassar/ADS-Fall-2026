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
public:
    LinkedList(): head(nullptr) {}

    void push_back(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* currNode = head;
            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }
            currNode->next = new Node(data);
        }
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

    return 0;
}