// https://leetcode.com/problems/move-zeroes/
// https://en.wikipedia.org/wiki/In-place_algorithm

/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int index = 0;
        for (auto k : nums)
        {
            if (k != 0)
            {
                nums[index++] = k;
            }
        }
        for (int i = index; i < n; i++)
        {
            nums[i] = 0;
        }
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
    obj.moveZeroes(v);
    for (auto k : v)
    {
        cout << k << " ";
    }
    return 0;
}