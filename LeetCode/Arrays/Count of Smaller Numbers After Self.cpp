// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Difficulty - Hard

/*You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].



Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:

Input: nums = [-1]
Output: [0]

Example 3:

Input: nums = [-1,-1]
Output: [0,0]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void merge_sort(int start, int end, vector<pair<int, int>> &nums, vector<int> &ans, vector<pair<int, int>> &temp)
    {
        if (start >= end)
        {
            return;
        }

        int mid = start + (end - start) / 2;

        merge_sort(start, mid, nums, ans, temp);
        merge_sort(mid + 1, end, nums, ans, temp);

        int index = start, left = start, right = mid + 1, numRightSmallThanLeft = 0;
        while (left <= mid && right <= end)
        {
            if (nums[left] > nums[right])
            {
                temp[index++] = nums[right++];
                numRightSmallThanLeft++;
            }
            else if (nums[left] <= nums[right])
            {
                ans[nums[left].second] += numRightSmallThanLeft;
                temp[index++] = nums[left++];
            }
        }

        while (left <= mid)
        {
            ans[nums[left].second] += numRightSmallThanLeft;
            temp[index++] = nums[left++];
        }
        while (right <= end)
        {
            temp[index++] = nums[right++];
        }

        for (int i = start; i <= end; i++)
        {
            nums[i] = temp[i];
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> new_nums;
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++)
        {
            new_nums.push_back({nums[i], i});
            temp.push_back({nums[i], i});
        }

        merge_sort(0, n - 1, new_nums, ans, temp);
        return ans;
    }
};