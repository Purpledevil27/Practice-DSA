// https://leetcode.com/problems/subarray-sums-divisible-by-k/

/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7

Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0

Constraints:

1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
2 <= k <= 10^4

*/

#include <bits/stdc++.h>
using namespace std;

// Using array
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> v(k, 0);

        int rem = 0;
        v[rem]++;

        int sum = 0, count = 0;

        for (auto i : nums)
        {
            sum += i;
            int rem = ((sum % k) + k) % k;

            // adding k if remainder is negative
            /*if(rem<0){
                rem+=k;
            }*/

            count += v[rem];
            v[rem]++;
        }
        return count;
    }
};

// Using hashmap
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            // adding k if remainder is negative
            if (rem < 0)
            {
                rem += k;
            }
            // finding if the same remainder is present in the map
            if (m.find(rem) != m.end())
            {
                count += m[rem];
            }
            // adding/incrementing the remainder in map
            m[rem]++;
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
    cout << obj.subarraysDivByK(v, t);
    return 0;
}