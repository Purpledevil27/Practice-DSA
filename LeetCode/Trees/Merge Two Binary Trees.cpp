// https://leetcode.com/problems/merge-two-binary-trees/

/*You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as
the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

Example 1:

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]

Constraints:

The number of nodes in both trees is in the range [0, 2000].
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

// Approach #1
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL)
        {
            return root2;
        }
        if (root2 == NULL)
        {
            return root1;
        }
        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

// Approach #2
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *root = new TreeNode(0);
        if (root1 && root2)
        {
            int num1 = root1->val;
            int num2 = root2->val;
            root->val = (num1 + num2);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }
        else if (!root1 && root2)
        {
            int num1 = root2->val;
            root->val = (num1);
            root->left = mergeTrees(NULL, root2->left);
            root->right = mergeTrees(NULL, root2->right);
        }
        else if (root1 && !root2)
        {
            int num1 = root1->val;
            root->val = (num1);
            root->left = mergeTrees(root1->left, NULL);
            root->right = mergeTrees(root1->right, NULL);
        }
        else
        {
            return NULL;
        }
        return root;
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
    TreeNode *root1 = takeInputLevelWise();
    TreeNode *root2 = takeInputLevelWise();
    Solution obj;
    cout << obj.mergeTrees(root1, root2);
    // printTreeLevelWise(root);
    return 0;
}