// https://leetcode.com/problems/maximum-width-of-binary-tree/

/*Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

Constraints:
The number of nodes in the tree is in the range [1, 3000].
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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            int min = q.front().second, first, last;
            for (int i = 0; i < size; i++)
            {
                auto p = q.front();
                q.pop();
                TreeNode *t = p.first;
                long long index = p.second - min;
                if (i == 0)
                    first = index;
                if (i == size - 1)
                    last = index;
                if (t->left)
                {
                    q.push({t->left, index * 2 + 1});
                }
                if (t->right)
                {
                    q.push({t->right, index * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};