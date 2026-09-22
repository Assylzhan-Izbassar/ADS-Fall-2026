#include <iostream>

using namespace std;

class Node {
public:
    int value;

    Node* left;
    Node* right;
    Node(int value): value(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* insertRec(Node* node, int newVal) { // O(log(n))
        if (node == nullptr) {
            return new Node(newVal);
        }
        if (node->value > newVal) {
            node->left = insertRec(node->left, newVal);
        } else if (node->value < newVal) {
            node->right = insertRec(node->right, newVal);
        }
        return node;
    }

    Node* removeRec(Node* node, int val) {
        if (node == nullptr) {
            return;
        }
        if (node->value > val) {
            removeRec(node->left, val);
        } else if (node->value < val) {
            removeRec(node->right, val);
        } else {
            // Case 1: leaf node
            if (!(node->left) && !(node->right)) {
                delete node;
            }
            // Case 2: leaf node
            else if (!(node->left) || !(node->right)) {
                if (!(node->left)) {
                    // right
                } else {
                    // left
                }
            }

            // Case 3: leaf node
        }
    }

    bool searchRec(Node* node, int val) { // Time complexity: O(log(n))
        if (node == nullptr) {
            return false;
        }
        if (node->value == val) {
            return true;
        }
        bool result = false;
        if (node->value > val) {
            result = searchRec(node->left, val);
        } else if (node->value < val) {
            result = searchRec(node->right, val);
        }
        return result;
    }

    int minElementRec(Node* node) { // O(log(n))
        if (node->left == nullptr) {
            return node->value;
        }
        return minElementRec(node->left);
    }

    int maxElementRec(Node* node) { // O(log(n))
        if (node->right == nullptr) {
            return node->value;
        }
        return maxElementRec(node->right);
    }

    void inorderTravRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTravRec(node->left);
        cout << node->value << " ";
        inorderTravRec(node->right);
    }

    void preorderTravRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << " ";
        inorderTravRec(node->left);
        inorderTravRec(node->right);
    }

    void postorderTravRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderTravRec(node->left);
        postorderTravRec(node->right);
        cout << node->value << " ";
    }
public:
    Node* root;

    BST(): root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    void remove(int val) {
        if (search(val)) {
            removeRec(root, val);
        }
    } 

    bool search(int val) {
        return searchRec(root, val);
    }

    int maxElement() {
        return maxElementRec(root);
    }

    int minElement() {
        return minElementRec(root);
    }

    void inorderTrav() {
        inorderTravRec(root);
    }

    void preorderTrav() {
        preorderTravRec(root);
    }

    void postorderTrav() {
        postorderTravRec(root);
    }
};

int main() {

    BST* bst = new BST();

    bst->insert(6);
    bst->insert(3);
    bst->insert(4);
    bst->insert(7);
    bst->insert(10);

    if (bst->search(3)) {
        cout << "FOUND\n"; 
    } else {
        cout << "NOT FOUND\n";
    }

    cout << bst->minElement() << "\n";
    cout << bst->maxElement() << "\n";

    bst->inorderTrav();
    cout << endl;

    bst->preorderTrav();
    cout << endl;

    bst->postorderTrav();
    cout << endl;

    return 0;
}