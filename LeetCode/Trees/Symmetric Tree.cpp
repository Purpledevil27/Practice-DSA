// https://leetcode.com/problems/symmetric-tree/

/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:

The number of nodes in the tree is in the range [1, 1000].
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

// Using Recursion - Approach #1
class Solution
{
public:
    bool solve_recur(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        if (!root1 || !root2)
        {
            return false;
        }
        return root1->val == root2->val && solve_recur(root1->left, root2->right) && solve_recur(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        return solve_recur(root, root);
    }
};

// Using queue - Approach #2
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            // Store value in a vector levelwise
            while (size--)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left)
                {
                    q.push(front->left);
                    v.emplace_back(front->left->val);
                }
                else
                {
                    v.emplace_back(-101);
                }
                if (front->right)
                {
                    q.push(front->right);
                    v.emplace_back(front->right->val);
                }
                else
                {
                    v.emplace_back(-101);
                }
            }
            // check if it is a palindrome
            int start = 0, end = v.size() - 1;
            while (start < end)
            {
                if (v[start++] != v[end--])
                {
                    return false;
                }
            }
            // clear vector
            v.clear();
        }
        return true;
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
    cout << obj.isSymmetric(root);
    // printTreeLevelWise(root);
    return 0;
}