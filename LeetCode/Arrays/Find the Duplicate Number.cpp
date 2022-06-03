// https://leetcode.com/problems/find-the-duplicate-number/

/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:

1 <= n <= 10^5
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size() - 1, count = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            count = 0;
            for (auto i : nums)
            {
                if (i <= mid)
                {
                    count++;
                }
            }

            if (count <= mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a.push_back(k);
    }
    Solution obj;
    cout << obj.findDuplicate(a);
    return 0;
}