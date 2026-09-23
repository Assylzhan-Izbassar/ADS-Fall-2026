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
    Node* root;

    void inorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderRec(node->left);
        cout << node->value << " "; 
        inorderRec(node->right);
    }

    void postorderRec(Node* node) {
        if (node == nullptr) return;

        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->value << " ";
    }

    void preorderRec(Node* node) {
        if (!node) return;

        cout << node->value << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (node->value > value) {
            node->left = insertRec(node->left, value);
        } else if (node->value < value) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    bool searchRec(Node* node, int x) { // O(log(n))
        if (!node) return false;

        if (node->value == x) return true;
        else if (node->value > x) return searchRec(node->left, x);
        else return searchRec(node->right, x);
    }

    Node* removeRec(Node* node, int x) {
        if (!node) return node;

        if (node->value > x) {
            node->left = removeRec(node->left, x);
        } else if (node->value < x) {
            node->right = removeRec(node->right, x);
        } else {
            // case 1
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // case 2
            if (!node->left && node->right) {
                Node* copyRight = node->right;
                delete node;
                return copyRight;
            } else if (!node->right && node->left) {
                Node* copyLeft = node->left;
                delete node;
                return copyLeft;
            }
            // case 3
            if (node->left && node->right) {
                Node* copyNode = node->right;
                while (copyNode->left != nullptr) { // minimum
                    copyNode = copyNode->left;
                }
                node->value = copyNode->value;
                node->right = removeRec(node->right, copyNode->value);
            }
        }
        return node;
    }

    int getMaxRec(Node* node) { // O(log(n))
        if (!node->right) return node->value;
        return getMaxRec(node->right);
    }

    int getMinRec(Node* node) {
        // TODO: fill it!
        return -1;
    }
public:
    BST(): root(nullptr) {}

    void insert(int value) {
        Node* node = root;
        Node* parent = nullptr;
        bool isDublicate = false;
        bool fromLeft = true;

        while (node != nullptr) {
            parent = node;
            if (node->value > value) {
                node = node->left;
                fromLeft = true;
            } else if (node->value < value) {
                node = node->right;
                fromLeft = false;
            } else {
                isDublicate = true;
                break;
            }
        }
        if (!isDublicate) {
            node = new Node(value);
            if (parent != nullptr) {
                if (fromLeft) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            } else {
                root = node;
            }
        } else {
            cout << "DUBLICATE!\n";
        }
        // root = insertRec(root, value);
    }

    bool search(int x) {
        return searchRec(root, x);
    }

    void remove(int x) {
        if (search(x)) {
            root = removeRec(root, x);
        }
    }

    int getMax() {
        return getMaxRec(root);
    }

    int getMin() {
        return getMinRec(root);
    }

    void inorder() {
        inorderRec(root);
        cout << "\n";
    }

    void postorder() {
        postorderRec(root);
        cout << "\n";
    }

    void preorder() {
        preorderRec(root);
        cout << "\n";
    }
};

int main() {
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(6);
    bst->insert(3);
    bst->insert(3);
    bst->insert(2);
    bst->insert(2);
    bst->insert(4);
    bst->insert(7);

    bst->inorder();
    bst->postorder();
    bst->preorder();

    if (bst->search(5)) {
        cout << "FOUND\n"; 
    } else {
        cout << "NOT FOUND\n";
    }

    cout << bst->getMax() << endl;

    bst->remove(5);

    bst->inorder();

    return 0;
}