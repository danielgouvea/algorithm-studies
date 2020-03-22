#include <iostream>
#include <queue>
#include <stack>

using std::cout;
using std::queue;
using std::stack;

struct TreeNode {
    int value;
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};

    explicit TreeNode(int value) : value(value) {}
};

void printDepthFirstInOrder(const TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    stack<const TreeNode *> backtrack;
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

    cout << '\n';
}

void printDepthFirstInOrderRecursive(const TreeNode *node) {
    if (node == nullptr) {
        return;
    }

    printDepthFirstInOrderRecursive(node->left);
    cout << node->value << ' ';
    printDepthFirstInOrderRecursive(node->right);
}

void printBreadthFirst(const TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    queue<const TreeNode *> nextNodes;
    nextNodes.push(root);

    while(!nextNodes.empty()) {
        const TreeNode *node = nextNodes.front();
        nextNodes.pop();

        cout << node->value << ' ';

        if (node->left != nullptr) {
            nextNodes.push(node->left);
        }

        if (node->right != nullptr) {
            nextNodes.push(node->right);
        }
    }

    cout << '\n';
}

void printBreadthFirstRecursive(const TreeNode *node) {
    if (node == nullptr) {
        return;
    }

    cout << node->value << ' ';

    printBreadthFirstRecursive(node->left);
    printBreadthFirstRecursive(node->right);
}

int main() {
    cout << R"(       1       )" << '\n'
         << R"(     /   \     )" << '\n'
         << R"(    2     3    )" << '\n'
         << R"(   / \   / \   )" << '\n'
         << R"(  4   5 6   7  )" << "\n\n";
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Depth first in-order:\n";
    printDepthFirstInOrder(root);
    cout << "Depth first in-order (recursive):\n";
    printDepthFirstInOrderRecursive(root);
    cout << '\n';

    cout << "Breadth first:\n";
    printBreadthFirst(root);
    cout << "Breadth first (recursive):\n";
    printBreadthFirstRecursive(root);
    cout << '\n';

    return 0;
}
