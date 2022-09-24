// https://leetcode.com/problems/path-sum-iii/

/*Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints:
The number of nodes in the tree is in the range [0, 1000].
-10^9 <= Node.val <= 10^9
-1000 <= targetSum <= 1000
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

#define ll long long
class Solution
{
    void dfs(TreeNode *root, int const &target, ll &ans, ll sum, unordered_map<ll, ll> &m)
    {
        if (!root)
            return;

        sum += root->val;
        if (m[sum - target] > 0)
            ans += m[sum - target];

        m[sum]++;
        dfs(root->left, target, ans, sum, m);
        dfs(root->right, target, ans, sum, m);
        m[sum]--;
        sum = sum - (root->val);
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        unordered_map<ll, ll> m;
        m[0]++;
        ll ans = 0;
        dfs(root, targetSum, ans, 0, m);
        return ans;
    }
};