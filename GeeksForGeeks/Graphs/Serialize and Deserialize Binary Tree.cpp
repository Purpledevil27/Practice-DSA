// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
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
                s += ".null";
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
        // cout << s << endl;
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
            int k = data.substr(i, it - i) == "null" ? INT_MAX : stoi(data.substr(i, it - i));
            (k == INT_MAX) ? t->left = NULL : t->left = new TreeNode(k);
            i = it + 1;
            if (t->left)
                q.push(t->left);
            // for right
            it = find(data.begin() + i, data.end(), '.') - data.begin();
            k = data.substr(i, it - i) == "null" ? INT_MAX : stoi(data.substr(i, it - i));
            (k == INT_MAX) ? t->right = NULL : t->right = new TreeNode(k);
            i = it + 1;
            if (t->right)
                q.push(t->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));