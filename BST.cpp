#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Search for a value in the BST
TreeNode* search(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// Find the minimum value node in the BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a value from the BST
TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) return root;
    
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node to be deleted found
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    
    return root;
}

// Inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Helper function to delete the entire tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;

    // Insert values
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print inorder traversal
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Search for a value
    int searchValue = 40;
    TreeNode* searchResult = search(root, searchValue);
    if (searchResult != nullptr) {
        cout << "Value " << searchValue << " found in the BST." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the BST." << endl;
    }

    // Delete a node
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    cout << "Inorder traversal after deleting " << deleteValue << ": ";
    inorderTraversal(root);
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
