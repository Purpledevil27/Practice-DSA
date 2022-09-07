// https://leetcode.com/problems/construct-string-from-binary-tree/

/*Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.
Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:

Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"

Example 2:

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
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

class Solution
{
    void solve(TreeNode *root, string &ans)
    {
        if (root == NULL)
            return;
        string t = to_string(root->val);
        ans += t;
        if (!root->left && !root->right)
        {
            return;
        }
        ans.push_back('(');
        solve(root->left, ans);
        ans.push_back(')');
        if (root->right)
        {
            ans.push_back('(');
            solve(root->right, ans);
            ans.push_back(')');
        }
    }

public:
    string tree2str(TreeNode *root)
    {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};