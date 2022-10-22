// https://leetcode.com/problems/balanced-binary-tree/

/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time complexity - O(N)
class Solution
{
    int isBalancedhelper(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = isBalancedhelper(root->left);
        if (left == -1)
            return -1;
        int right = isBalancedhelper(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (isBalancedhelper(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

// Time complexity - O(N^2)
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(height(root->left), (height(root->right))) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        int hl = height(root->left);
        int hr = height(root->right);
        return (abs(hl - hr) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};

// Driver code
// Taking input is a bit different comapared to the example above
TreeNode *takeInputLevelWise()
{
    queue<TreeNode *> pendingNodes;
    int rootData;
    cout << "enter root data:";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(rootData);
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->val << endl;
        int leftinput;
        cin >> leftinput;
        if (leftinput != -1)
        {
            TreeNode *leftchild = new TreeNode(leftinput);
            front->left = leftchild;
            pendingNodes.push(leftchild);
        }
        cout << "Enter right child of " << front->val << endl;
        int rightinput;
        cin >> rightinput;
        if (rightinput != -1)
        {
            TreeNode *rightchild = new TreeNode(rightinput);
            front->right = rightchild;
            pendingNodes.push(rightchild);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode *front = pendingNodes.front();
        cout << front->val << ":";
        pendingNodes.pop();
        if (front->left != NULL)
        {
            cout << "L" << front->left->val;
            pendingNodes.push(front->left);
        }

        if (front->right != NULL)
        {
            cout << "R" << front->right->val;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    TreeNode *root = takeInputLevelWise();
    Solution obj;
    cout << obj.isBalanced(root);
    // printTreeLevelWise(root);
    return 0;
}