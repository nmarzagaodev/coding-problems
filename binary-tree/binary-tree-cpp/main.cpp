#include <iostream>

using namespace std;

class BinarySearchTreeNode {
public:
    int value;
    BinarySearchTreeNode* right, *left;

    BinarySearchTreeNode();
    BinarySearchTreeNode(int value);
};

BinarySearchTreeNode::BinarySearchTreeNode() {
    this->value = 0;
    this->right, this->left = nullptr;
}

BinarySearchTreeNode::BinarySearchTreeNode(int value) {
    this->value = value;
    this->right, this->left = nullptr;
}

void iterateInorder(BinarySearchTreeNode* root, void (*function)(BinarySearchTreeNode* current_node)) {
    if (root == nullptr) return;

    iterateInorder(root->left, function);
    function(root);
    iterateInorder(root->right, function);
}

BinarySearchTreeNode* recursiveInsert(BinarySearchTreeNode* root, int value) {
    if (root == nullptr) return new BinarySearchTreeNode(value);

    if (value > root->value) root->right = recursiveInsert(root->right, value);
    else if (value < root->value) root->left = recursiveInsert(root->left, value);

    return root;
}

// Implement Deletion here!
// https://www.geeksforgeeks.org/deletion-binary-tree/

int main(void) {
    BinarySearchTreeNode* root = new BinarySearchTreeNode();

    for (int i = 1; i < 5; i++) 
        recursiveInsert(root, i);

    iterateInorder(root, [] (auto current_node) {
        cout << current_node->value << " ";
    });
    cout << endl;

    return 0;
}