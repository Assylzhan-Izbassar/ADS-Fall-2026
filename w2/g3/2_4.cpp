#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
    T data;
    Node* next;
    Node* prev;

    Node(T data): data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* front;
public:
    DoubleLinkedList(): head(nullptr) {}

    void push_back(T data) {
        // TODO: Fill the method
    }

    void push_front(T data) {
        // TODO: Fill the method
    }
};

int main() {
    DoubleLinkedList<int>* ll = new DoubleLinkedList<int>();

    DoubleLinkedList<string>* ll = new DoubleLinkedList<string>();

    return 0;
}