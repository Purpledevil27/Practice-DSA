// https://leetcode.com/problems/contains-duplicate-iii/

/*
Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

Constraints:
1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^4
0 <= t <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        set<long> window;
        for (int i = 0; i < nums.size(); i++)
        {
            long n = nums[i];
            if (i > k)
                window.erase(nums[i - k - 1]);
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound(n - t); // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && (*pos - n) <= t)
                return true;
            window.insert(n);
        }
        return false;
    }
};

// Approach #2
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        vector<pair<long long, long long>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size() && abs(v[i].first - v[j].first) <= t; j++)
            {
                if (abs(v[i].second - v[j].second) <= k)
                    return true;
            }
        }
        return false;
    }
};