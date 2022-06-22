// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

/*Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:

The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5
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

// Using inorder traversal
class Solution
{
    void collect(TreeNode *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }

        collect(root->left, v);
        v.push_back(root->val);
        collect(root->right, v);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> v;
        collect(root, v);
        int ans = INT_MAX;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] - v[i - 1] < ans)
            {
                ans = v[i] - v[i - 1];
            }
        }
        return ans;
    }
};

// Driver code
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
    cout << obj.getMinimumDifference(root);
    // printTreeLevelWise(root);
    return 0;
}