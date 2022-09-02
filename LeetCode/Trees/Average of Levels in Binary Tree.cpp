// https://leetcode.com/problems/average-of-levels-in-binary-tree/

/*Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:

Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]

Constraints:
The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<double> ans;
        q.push(root);
        double sum = 0;
        int count = 1, prevc = 0, avg = 1;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            count--;
            sum += front->val;

            if (front->left)
            {
                prevc++;
                q.push(front->left);
            }
            if (front->right)
            {
                prevc++;
                q.push(front->right);
            }
            if (count == 0)
            {
                ans.push_back(sum / avg);
                sum = 0;
                count = prevc;
                avg = prevc;
                prevc = 0;
            }
        }
        return ans;
    }
};