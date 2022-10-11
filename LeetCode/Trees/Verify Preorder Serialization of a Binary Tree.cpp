// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

/*One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.

Example 1:

Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true

Example 2:

Input: preorder = "1,#"
Output: false

Example 3:

Input: preorder = "9,#,#,1"
Output: false

Constraints:
1 <= preorder.length <= 10^4
preorder consist of integers in the range [0, 100] and '#' separated by commas ','.
*/

#include <bits/stdc++.h>
using namespace std;

// O(1) space
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        preorder += ',';
        int sz = preorder.size(), idx = 0;
        int capacity = 1;
        for (idx = 0; idx < sz; idx++)
        {
            if (preorder[idx] != ',')
                continue;
            capacity--;
            if (capacity < 0)
                return false;
            if (preorder[idx - 1] != '#')
                capacity += 2;
        }
        return capacity == 0;
    }
};

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        if (preorder[0] == '#')
        {
            return preorder.size() <= 1 ? true : false;
        }
        if (preorder.size() == 1)
            return false;
        queue<string> q;
        int index = 0;
        auto it = find(preorder.begin() + index, preorder.end(), ',') - preorder.begin();
        q.push(preorder.substr(index, it - index));
        index = it + 1;
        while (!q.empty())
        {
            q.pop();
            it = find(preorder.begin() + index, preorder.end(), ',') - preorder.begin();
            if (preorder.substr(index, it - index) != "#")
            {
                q.push(preorder.substr(index, it - index));
            }
            index = it + 1;
            if (index > preorder.size())
                return false;
            it = find(preorder.begin() + index, preorder.end(), ',') - preorder.begin();
            if (preorder.substr(index, it - index) != "#")
            {
                q.push(preorder.substr(index, it - index));
            }
            index = it + 1;
        }
        return index > preorder.size() ? true : false;
    }
};