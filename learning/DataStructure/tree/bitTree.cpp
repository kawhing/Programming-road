#include <iostream>
#include <memory>
using namespace std;

struct TreeNode {
    char data;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    
    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// 前序遍历
void preOrder(const shared_ptr<TreeNode>& node) {
    if (node) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// 中序遍历
void inOrder(const shared_ptr<TreeNode>& node) {
    if (node) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// 后序遍历
void postOrder(const shared_ptr<TreeNode>& node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}


int main() {
    // 快速创建树
    auto root = make_shared<TreeNode>('A');
    root->left = make_shared<TreeNode>('B');
    root->right = make_shared<TreeNode>('C');
    root->left->left = make_shared<TreeNode>('D');
    root->left->right = make_shared<TreeNode>('E');
    
    cout << "前序遍历: ";
    preOrder(root);
    cout << endl;
    
    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;
    
    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;
    
    return 0;
}