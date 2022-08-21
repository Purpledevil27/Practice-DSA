// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

/*You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.

Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
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
    void create(vector<vector<int>> &adj, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        create(adj, root->left);
        create(adj, root->right);
    }
    int findMax(TreeNode *root)
    {
        // Base case
        if (root == NULL)
            return INT_MIN;

        int res = root->val;
        int lres = findMax(root->left);
        int rres = findMax(root->right);
        if (lres > res)
            res = lres;
        if (rres > res)
            res = rres;
        return res;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        // Finding the max node of the tree
        int num = findMax(root);
        // creating a adjacency matrix for the tree, a undirected graph
        vector<vector<int>> adj(num + 1);
        create(adj, root);

        int ans = 0;
        queue<int> q;
        vector<bool> vis(num + 1, false);

        q.push(start);
        q.push(-1);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (front == -1)
            {
                if (!q.empty())
                {
                    ans++;
                    q.push(-1);
                }
                continue;
            }
            vis[front] = true;

            for (auto &i : adj[front])
            {
                if (!vis[i])
                    q.push(i);
            }
        }

        return ans;
    }
};