// https://leetcode.com/problems/majority-element/

/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9

*/

#include <bits/stdc++.h>
using namespace std;

// Time complexity O(n) and space complexity O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == num)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    num = nums[i];
                    count = 1;
                }
            }
        }
        return num;
    }
};

// Using maps
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int count = INT_MIN, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            if (count < m[nums[i]])
            {
                ans = nums[i];
                count = m[nums[i]];
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    Solution obj;
    cout << obj.majorityElement(v);
    return 0;
}