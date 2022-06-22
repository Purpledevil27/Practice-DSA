// https://leetcode.com/problems/sum-of-left-leaves/

/*Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
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

// Recursive - Approach #1
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        if (root->left && root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->val;
        }
        else if (root->left)
        {
            sum += sumOfLeftLeaves(root->left);
        }
        if (root->right)
        {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};

// Iterative - Approach #2
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root->left and !root->right)
            return 0;

        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left and (!temp->left->left and !temp->left->right))
                    sum += temp->left->val;

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
        }
        return sum;
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
    cout << obj.sumOfLeftLeaves(root);
    // printTreeLevelWise(root);
    return 0;
}