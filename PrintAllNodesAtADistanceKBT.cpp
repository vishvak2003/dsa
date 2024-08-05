#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to print nodes at distance k from a given node
void printKDistanceDown(TreeNode* node, int k) {
    if (node == nullptr || k < 0) return;

    if (k == 0) {
        cout << node->val << " ";
        return;
    }

    printKDistanceDown(node->left, k - 1);
    printKDistanceDown(node->right, k - 1);
}

// Function to find nodes at distance k from a given node
int printNodesAtDistanceK(TreeNode* root, TreeNode* target, int k) {
    if (root == nullptr) return -1;

    if (root == target) {
        printKDistanceDown(root, k);
        return 0;
    }

    int leftDist = printNodesAtDistanceK(root->left, target, k);
    if (leftDist != -1) {
        if (leftDist + 1 == k) cout << root->val << " ";
        else printKDistanceDown(root->right, k - leftDist - 2);
        return leftDist + 1;
    }

    int rightDist = printNodesAtDistanceK(root->right, target, k);
    if (rightDist != -1) {
        if (rightDist + 1 == k) cout << root->val << " ";
        else printKDistanceDown(root->left, k - rightDist - 2);
        return rightDist + 1;
    }

    return -1;
}

// Helper function to print inorder traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    TreeNode* target = root->left; // Node with value 2
    int k = 2;

    cout << "Inorder traversal of the tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Nodes at distance " << k << " from node with value " << target->val << ": ";
    printNodesAtDistanceK(root, target, k);
    cout << endl;

    return 0;
}
