// https://leetcode.com/problems/next-greater-element-i/

/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

*/
#include <bits/stdc++.h>
using namespace std;

// Using Stack and Maps
// TC - O(nums1.size() + nums2.size())
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> m;
        stack<int> s;
        s.push(-1);
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (s.top() < nums2[i] && s.size() > 1)
            {
                s.pop();
            }
            m[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};

// Traversing through both arrays
// TC - O(nums1.size() * nums2.size())
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        bool found = false;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (found && nums2[j] > nums1[i])
                {
                    ans.push_back(nums2[j]);
                    found = false;
                    break;
                }
                if (nums1[i] == nums2[j])
                {
                    found = true;
                }
            }
            if (found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
