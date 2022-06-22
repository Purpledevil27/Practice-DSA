// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

/*Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, ans);
        ans.emplace_back(root->val);
        solve(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Using Stack - Iterative Approach (#2)
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        s.push(root);
        if (root == NULL)
        {
            return ans;
        }
        while (!s.empty())
        {
            TreeNode *top = s.top();
            if (top->left)
            {
                s.push(top->left);
                top->left = NULL;
            }
            else
            {
                ans.push_back(top->val);
                s.pop();
                if (top->right)
                {
                    s.push(top->right);
                }
            }
        }
        return ans;
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
    vector<int> ans = obj.inorderTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    // printTreeLevelWise(root);
    return 0;
}