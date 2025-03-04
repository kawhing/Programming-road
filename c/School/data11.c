#include <stdio.h>
#include <stdlib.h>

// 顺序查找
int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // 返回索引
        }
    }
    return -1; // 未找到
}

// 折半查找
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // 返回索引
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // 未找到
}

// 二叉排序树节点定义
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// 插入节点到二叉排序树
TreeNode* insertBST(TreeNode *root, int value) {
    if (root == NULL) {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }
    return root;
}

// 二叉排序树查找
TreeNode* searchBST(TreeNode *root, int target) {
    if (root == NULL || root->data == target) {
        return root; // 找到或未找到
    }
    if (target < root->data) {
        return searchBST(root->left, target);
    } else {
        return searchBST(root->right, target);
    }
}

// 平衡二叉树节点定义 (AVL树)
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

// 获取节点高度
int height(AVLNode *node) {
    return node ? node->height : 0;
}

// 更新节点高度
int max(int a, int b) {
    return a > b ? a : b;
}

// 单右旋
AVLNode* rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// 单左旋
AVLNode* rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// 获取平衡因子
int getBalance(AVLNode *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// 插入节点到AVL树
AVLNode* insertAVL(AVLNode *node, int value) {
    if (node == NULL) {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    if (value < node->data) {
        node->left = insertAVL(node->left, value);
    } else if (value > node->data) {
        node->right = insertAVL(node->right, value);
    } else {
        return node; // 不允许重复
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // 左左情况
    if (balance > 1 && value < node->left->data) {
        return rotateRight(node);
    }
    // 右右情况
    if (balance < -1 && value > node->right->data) {
        return rotateLeft(node);
    }
    // 左右情况
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // 右左情况
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// AVL树查找
AVLNode* searchAVL(AVLNode *root, int target) {
    if (root == NULL || root->data == target) {
        return root; // 找到或未找到
    }
    if (target < root->data) {
        return searchAVL(root->left, target);
    } else {
        return searchAVL(root->right, target);
    }
}

// 主函数测试
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    printf("顺序查找: %d\n", sequentialSearch(arr, size, target));

    printf("折半查找: %d\n", binarySearch(arr, size, target));

    // 构建二叉排序树
    TreeNode *bstRoot = NULL;
    for (int i = 0; i < size; i++) {
        bstRoot = insertBST(bstRoot, arr[i]);
    }
    TreeNode *bstResult = searchBST(bstRoot, target);
    if (bstResult != NULL) {
        printf("二叉排序树查找: %d\n", bstResult->data);
    } else {
        printf("二叉排序树查找: 未找到\n");
    }

    // 构建AVL树
    AVLNode *avlRoot = NULL;
    for (int i = 0; i < size; i++) {
        avlRoot = insertAVL(avlRoot, arr[i]);
    }
    AVLNode *avlResult = searchAVL(avlRoot, target);
    if (avlResult != NULL) {
        printf("平衡二叉树查找: %d\n", avlResult->data);
    } else {
        printf("平衡二叉树查找: 未找到\n");
    }

    return 0;
}
