// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Approach #1
int change(BinaryTreeNode<int> *root, int par)
{
    if (!root)
        return 0;
    int l = change(root->left, max(root->data, par));
    int r = change(root->right, max(root->data, par));
    root->data = max(l + r, max(root->data, par));
    return root->data;
}

void changeTree(BinaryTreeNode<int> *root)
{
    change(root, 0);
}

// Approach #2
int maxi = INT_MIN;
void changeTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    if (root->left == root->right)
    {
        return;
    }
    if (root->data > maxi)
    {
        maxi = root->data;
    }
    int sum = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
    if (sum >= maxi)
    {
        root->data = sum;
        maxi = root->data;
    }
    else
    {
        if (root->left)
            root->left->data = maxi;
        if (root->right)
            root->right->data = maxi;
    }
    changeTree(root->left);
    changeTree(root->right);
    root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}