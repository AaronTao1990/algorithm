#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):value(value), left(NULL), right(NULL) {}
};

TreeNode* createBinaryTreeFromArray(int* array, int len, int idx) {
    if (idx >= len) return NULL;
    if (array[idx] == -1) return NULL;
    TreeNode* node = new TreeNode(array[idx]);
    TreeNode* left = createBinaryTreeFromArray(array, len, idx*2+1);
    TreeNode* right = createBinaryTreeFromArray(array, len, idx*2+2);
    node->left = left;
    node->right = right;
    return node;
}

void preOrder(TreeNode* node) {
    if (node == NULL) return;
    cout << node->value << endl;
    preOrder(node->left);
    preOrder(node->right);
}

void preOrderNonRecursion(TreeNode* node) {
    if (node == NULL) return;
    stack<TreeNode*> s;
    TreeNode* n = node;
    while(n || !s.empty()) {
        while (n) {
            cout << n->value << endl;
            s.push(n);
            n = n->left;
        }
        if (!s.empty()) {
            TreeNode* n1 = s.top();
            s.pop();
            n = n1->right;
        }
    }
}

void inOrder(TreeNode* node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->value << endl;
    inOrder(node->right);
}

void inOrderNonRecursion(TreeNode* node) {
    if (node == NULL) return;
    stack<TreeNode*> s;
    TreeNode* n = node;
    while (n || !s.empty()) {
        while (n) {
            s.push(n);
            n = n->left;
        }

        if (!s.empty()) {
            TreeNode* n1 = s.top();
            s.pop();
            cout << n1->value << endl;
            n = n1->right;
        }
    }
}

void postOrder(TreeNode* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << endl;
}

void postOrderNonRecursion(TreeNode* node) {
    if (node == NULL) return;
    TreeNode* pre = NULL;
    stack<TreeNode*> s;
    s.push(node);
    while (!s.empty()) {
        TreeNode* n = s.top();
        if ((n->left == NULL && n->right == NULL) ||
                (pre!=NULL && (pre==n->left || pre==n->right))) {
            cout << n->value << endl;
            pre = n;
            s.pop();
        } else {
            if (n->right) {
                s.push(n->right);
            }
            if (n->left) {
                s.push(n->left);
            }
        }
    }
}

void breadthFirstSearch(TreeNode* node) {
    if (node == NULL) return;
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()) {
        TreeNode* node = q.front();
        cout << node->value << endl;
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {

    int a[] = {1, 2, 3, -1, 4, 5};
    TreeNode* root = createBinaryTreeFromArray(a, sizeof(a)/sizeof(int), 0);
    cout << "-----------pre order-------------" << endl;
    preOrder(root);
    cout << "-----------pre order non recur-------------" << endl;
    preOrderNonRecursion(root);
    cout << "-----------in order-------------" << endl;
    inOrder(root);
    cout << "-----------in order non recur-------------" << endl;
    inOrderNonRecursion(root);
    cout << "-----------post order-------------" << endl;
    postOrder(root);
    cout << "-----------post order non recursion-------------" << endl;
    postOrderNonRecursion(root);
    cout << "-----------bfs order-------------" << endl;
    breadthFirstSearch(root);
}
