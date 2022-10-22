// https://leetcode.com/problems/diameter-of-binary-tree/

/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1

Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-100 <= Node.val <= 100
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
    int height(TreeNode *root, int &dia)
    {
        if (root == NULL)
            return 0;
        int lefDia = height(root->left, dia);
        int rigDia = height(root->right, dia);
        dia = max(dia, lefDia + rigDia);
        return max(lefDia, rigDia) + 1; // returns the max height
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int dia = 0;
        height(root, dia);
        return dia;
    }
};

// Approach #2
class Solution
{
public:
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            // first is the height and second is the diameter
            pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int lh = left.first;
        int rh = right.first;
        int ld = left.second;
        int rd = right.second;

        pair<int, int> ans;
        ans.first = 1 + max(lh, rh);
        ans.second = max(lh + rh, max(ld, rd));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        return solve(root).second;
    }
};

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
    cout << obj.diameterOfBinaryTree(root);
    // printTreeLevelWise(root);
    return 0;
}