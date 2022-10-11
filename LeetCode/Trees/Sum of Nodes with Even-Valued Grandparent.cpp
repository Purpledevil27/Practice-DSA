// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

/*Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.

Example 1:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Example 2:

Input: root = [1]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 100
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

class Solution
{
public:
    int sumEvenGrandparent(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->val % 2 == 0)
                {
                    if (t->left)
                    {
                        TreeNode *temp = t->left;
                        if (temp->left)
                            ans += temp->left->val;
                        if (temp->right)
                            ans += temp->right->val;
                    }
                    if (t->right)
                    {
                        TreeNode *temp = t->right;
                        if (temp->left)
                            ans += temp->left->val;
                        if (temp->right)
                            ans += temp->right->val;
                    }
                }
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return ans;
    }
};