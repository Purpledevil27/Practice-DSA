// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

/*In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

Example 1:

Input: label = 14
Output: [1,3,4,14]

Example 2:

Input: label = 26
Output: [1,2,6,10,26]

Constraints:
1 <= label <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

// Bottom-up approach
class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> result;
        result.push_back(label);
        // find the height
        int height = log2(label);
        while (height)
        {
            int left = pow(2, height - 1);  // left side of the level
            int right = pow(2, height) - 1; // right side of the level
            // right-label/2 is the distance from the right of the original parent
            // adding left takes it to the zigzag order parent
            label = left + (right - label / 2);
            result.push_back(label);
            height--;
        }
        // reverse the array to get the top down result
        reverse(result.begin(), result.end());
        return result;
    }
};