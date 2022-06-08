// https://leetcode.com/problems/subarray-sum-equals-k/

/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

Constraints:

1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, sum = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        m[sum] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
            {
                count += m[sum - k];
            }
            m[sum]++;
        }
        return count;
    }
};

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    Solution obj;
    cout << obj.subarraySum(v, t);
    return 0;
}