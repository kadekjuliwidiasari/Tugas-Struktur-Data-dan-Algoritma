#include <iostream>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int key;

    Node() {
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insertRecursive(int inputKey, Node *currentRoot) {
        if (currentRoot == NULL) {
            Node *newNode = new Node();
            newNode->key = inputKey;
            return newNode;
        }
        if (inputKey < currentRoot->key) {
            currentRoot->left = insertRecursive(inputKey, currentRoot->left);
        } else if (inputKey > currentRoot->key) {
            currentRoot->right = insertRecursive(inputKey, currentRoot->right);
        }

        return currentRoot;
    }

    void insert(int inputKey) {
        root = insertRecursive(inputKey, root);
    }

    void preOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            cout << currentNode->key << " ";
            preOrderTraversal(currentNode->left);
            preOrderTraversal(currentNode->right);
        }
    }
    
    void preOrder() {
        cout << "Pre Order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            postOrderTraversal(currentNode->left);
            postOrderTraversal(currentNode->right);
            cout << currentNode->key << " ";
        }
    }
    
    void postOrder() {
        cout << "Post Order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            inOrderTraversal(currentNode->left);
            cout << currentNode->key << " ";
            inOrderTraversal(currentNode->right);
        }
    }
    
    void inOrder() {
        cout << "In Order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    void findMax(Node *currentNode) {
        if (currentNode == NULL) {
            cout << "Tree is empty" << endl;
            return;
        }
        while (currentNode != NULL && currentNode->right != NULL) {
            currentNode = currentNode->right;
        }
        cout << "Max value: " << currentNode->key << endl;
    }
    
    void findMax() {
        cout << "Finding Max value: ";
        findMax(root);
    }

    void findMin(Node *currentNode) {
        if (currentNode == NULL) {
            cout << "Tree is empty" << endl;
            return;
        }
        while (currentNode != NULL && currentNode->left != NULL) {
            currentNode = currentNode->left;
        }
        cout << "Min value: " << currentNode->key << endl;
    }
    
    void findMin() {
        cout << "Finding Min value: ";
        findMin(root);
    }

    void search(int target, Node *currentNode) {
        if (currentNode == NULL) {
            cout << "Value " << target << " not found in the tree" << endl;
            return;
        }
        if (target == currentNode->key) {
            cout << "Value " << target << " found in the tree" << endl;
            return;
        }
        if (target < currentNode->key) {
            search(target, currentNode->left);
        } else {
            search(target, currentNode->right);
        }
    }
    
    void search(int target) {
        search(target, root);
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }
};

int main(int argc, char** argv) {
    BST *bin1 = new BST();
    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(8);
    bin1->insert(5);
    bin1->insert(3);

    bin1->preOrder();
    bin1->inOrder();
    bin1->postOrder();
    bin1->findMax();
    bin1->findMin();

    int target = 9;
    bin1->search(target);

    bin1->deleteKey(5); // Deleting node with key 5
    cout << "After deleting 5:" << endl;
    bin1->inOrder();

    return 0;
}