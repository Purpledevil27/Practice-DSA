// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = 0; // flag = 0 means left to right and if flag = 1 means right to left
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                int index = flag ? size - i - 1 : i;
                temp[index] = t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};