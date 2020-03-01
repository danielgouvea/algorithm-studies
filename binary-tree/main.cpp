#include <iostream>
#include <stack>

using std::cout;
using std::stack;

struct TreeNode {
    int value;
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};

    explicit TreeNode(int value) : value(value) {}
};

void printDepthFirstInOrder(const TreeNode *root) {
    stack<const TreeNode *> backtrack;

    if (root == nullptr) {
        return;
    }

    const TreeNode *current = root;
    backtrack.push(root);

    while(!backtrack.empty()) {
        if (current->left != nullptr) {
            backtrack.push(current->left);
            current = current->left;
        } else {
            current = backtrack.top();
            backtrack.pop();

            cout << current->value << ' ';

            if (current->right != nullptr) {
                backtrack.push(current->right);
                current = current->right;
            }
        }
    }
}

void printBreadthFirst(const TreeNode *root) {

}

int main() {
    //       1
    //     /   \
    //    2     3
    //   / \   / \
    //  4   5 6   7
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printDepthFirstInOrder(root);
    printBreadthFirst(root);

    return 0;
}
