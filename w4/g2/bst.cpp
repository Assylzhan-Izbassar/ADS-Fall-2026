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

    Node* insertRec(Node* node, int newValue) {
        if (node == nullptr) {
            return new Node(newValue);
        }
        if (node->value > newValue) {
            node->left = insertRec(node->left, newValue);
        } else if (node->value < newValue) {
            node->right = insertRec(node->right, newValue);
        }
        return node;
    }

    Node* removeRec(Node* node, int value) {
        if (node->value == value) {
            // case1
            if (!(node->left) && !(node->right)) {
                delete node;
                return nullptr;
            }
            // case2
            else if ((!(node->left) && (node->right)) || (!(node->right) && (node->left))) {
               if (!node->left) {
                Node* nodeRight = node->right;
                delete node;
                return nodeRight;
               } else {
                Node* nodeLeft = node->left;
                delete node;
                return nodeLeft;
               } 
            }
            // case3
            else {
                Node* toBeReplaced = node->right;
                while (true) {
                    if (!toBeReplaced && toBeReplaced ->left == nullptr && toBeReplaced->right == nullptr) {
                        break;
                    }
                    if (toBeReplaced->right != nullptr) {
                        toBeReplaced = toBeReplaced->right;
                        if (toBeReplaced->left != nullptr) {
                            toBeReplaced = toBeReplaced->left;
                        }
                    }
                }
                node->value = toBeReplaced->value;
                delete toBeReplaced;
                return node;
            }

        } else if (node->value > value) {
            node->left = removeRec(node->left, value);
        } else {
            node->right = removeRec(node->right, value);
        }
        return node;
    }

    bool searchRec(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (node->value > value) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }

    int getMaxRec(Node* node) {
        if (node->right == nullptr) {
            return node->value;
        }
        return getMaxRec(node->right);
    }

    void inorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderRec(node->left);
        cout << node->value << " ";
        inorderRec(node->right);
    }

    void preorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->value << " ";
    }
public:
    BST(): root(nullptr) {}

    void insert(int newValue) {
        root = insertRec(root, newValue);
    }

    void remove(int value) {
        if (search(value)) {
            root = removeRec(root, value);
        }
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    int getMax(){
        return getMaxRec(root);
    }

    // TODO: getMin() {...}

    void inorder() {
        inorderRec(root);
    }

    void preorder() {
        preorderRec(root);
    }

    void postorder() {
        postorderRec(root);
    }
};

int main() {
    BST* bst = new BST();

    bst->insert(8);
    bst->insert(5);
    bst->insert(10);
    bst->insert(11);
    bst->insert(1);
    bst->insert(3);

    cout << bst->getMax() << endl;

    bst->inorder();
    cout << "\n";
    bst->preorder();
    cout << "\n";
    bst->postorder();

    cout << "\n";

    if (bst->search(0)) {
        cout << "FOUND\n";
    } else {
        cout << "NOT FOUND\n";
    }

    bst->remove(5);
    bst->inorder();
    cout << "\n";

    return 0;
}