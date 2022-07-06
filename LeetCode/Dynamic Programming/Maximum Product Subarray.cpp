// https://leetcode.com/problems/maximum-product-subarray/

/*Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:

1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N) - Kadane algo variant
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int minp = nums[0], maxp = nums[0], ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(minp, maxp);
            }
            minp = min(nums[i], minp * nums[i]);
            maxp = max(nums[i], maxp * nums[i]);
            ans = max(ans, maxp);
        }
        return ans;
    }
};

// Time Complexity - O(N^2)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                t = t * nums[j];
                if (t > ans)
                {
                    ans = t;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.maxProduct(nums);
    return 0;
}