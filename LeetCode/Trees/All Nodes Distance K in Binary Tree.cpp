// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:

Input: root = [1], target = 1, k = 3
Output: []

Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
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
    vector<int> ans;
    int rem;

public:
    void bottom(TreeNode *root, int k)
    {
        if (root == NULL || k < 0)
        {
            return;
        }
        if (k == 0)
        {
            ans.push_back(root->val);
        }
        bottom(root->left, k - 1);
        bottom(root->right, k - 1);
    }
    TreeNode *find(TreeNode *root, TreeNode *target)
    {
        if (!root)
        {
            return NULL;
        }
        if (root == target)
        {
            return target;
        }
        TreeNode *l = find(root->left, target);
        TreeNode *r = find(root->right, target);
        if (l == target || r == target)
        {
            if (rem > 0)
            {
                if (rem == 1)
                {
                    ans.push_back(root->val);
                    rem--;
                    return target;
                }
                if (l == target)
                {
                    bottom(root->right, rem - 2);
                    rem--;
                }
                else
                {
                    bottom(root->left, rem - 2);
                    rem--;
                }
            }
            return target;
        }
        return NULL;
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        rem = k;
        TreeNode *t = find(root, target);
        if (t == NULL)
            return ans;
        bottom(t, k);
        return ans;
    }
};