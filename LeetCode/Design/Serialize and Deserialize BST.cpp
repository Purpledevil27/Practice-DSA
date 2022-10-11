// https://leetcode.com/problems/serialize-and-deserialize-bst/

/*Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]

Example 2:

Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
0 <= Node.val <= 10^4
The input tree is guaranteed to be a binary search tree.
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

class Codec
{
public:
    void solve(TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t == NULL)
            {
                s += ".n";
                continue;
            }
            (s.size() == 0) ? s += to_string(t->val) : s += ("." + to_string(t->val));
            q.push(t->left);
            q.push(t->right);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        solve(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        TreeNode *ans = NULL;
        int i = 0, n = data.size();
        auto it = find(data.begin() + i, data.end(), '.') - data.begin();
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(data.substr(i, it - i)));
        i = it + 1;
        q.push(root);
        while (!q.empty() && i < n)
        {
            TreeNode *t = q.front();
            q.pop();
            // for left
            auto it = find(data.begin() + i, data.end(), '.') - data.begin();
            int k = data.substr(i, it - i) == "n" ? INT_MAX : stoi(data.substr(i, it - i));
            (k == INT_MAX) ? t->left = NULL : t->left = new TreeNode(k);
            i = it + 1;
            if (t->left)
                q.push(t->left);
            // for right
            it = find(data.begin() + i, data.end(), '.') - data.begin();
            k = data.substr(i, it - i) == "n" ? INT_MAX : stoi(data.substr(i, it - i));
            (k == INT_MAX) ? t->right = NULL : t->right = new TreeNode(k);
            i = it + 1;
            if (t->right)
                q.push(t->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;