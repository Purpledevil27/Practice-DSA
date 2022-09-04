// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column.
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
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
    void apply(TreeNode *root, int r, int c, vector<pair<pair<int, int>, int>> &v)
    {
        if (root == NULL)
            return;
        // giving row col to the vector as {{col, row}, node->value} so that when we sort it, first priority is column and then row and then value
        v.push_back({{c, r}, root->val});
        apply(root->left, r + 1, c - 1, v);
        apply(root->right, r + 1, c + 1, v);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        int r = 0, c = 0;
        // Create a vector to store {row, col} for every node in the tree
        vector<pair<pair<int, int>, int>> v;
        // find row & col for every node
        apply(root, r, c, v);
        // sort the vector
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int i = 0; i < v.size(); i++)
        {
            // starting the newer column
            if (ans.size() == 0 || v[i - 1].first.first != v[i].first.first)
                ans.push_back({v[i].second});
            // pushing into the same column
            else
                ans[ans.size() - 1].push_back(v[i].second);
        }
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto it = q.front();

            TreeNode *node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mpp[x][y].insert(node->val);

            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
            q.pop();
        }
        vector<vector<int>> ans;

        for (auto p : mpp)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};