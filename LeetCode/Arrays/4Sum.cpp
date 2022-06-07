// https://leetcode.com/problems/4sum/

/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> v;

        // Sorting
        sort(nums.begin(), nums.end());

        for (int l = 0; l < n - 3; l++)
        {
            // Target for three numbers
            int target_3num = target - nums[l];

            // Skipping duplicates
            if (l != 0 && nums[l] == nums[l - 1])
            {
                continue;
            }
            for (int k = l + 1; k < n - 2; k++)
            {

                // Skipping Duplicates
                if (k != l + 1 && nums[k] == nums[k - 1])
                {
                    continue;
                }

                // Target for two numbers
                int target_2num = target_3num - nums[k];

                // incrementing l by breaking this loop, because further no value of i and j can be equal to target for two numbers i.e. it will always be greater than our target.
                if (nums[k + 1] + nums[k + 2] > target_2num)
                {
                    break;
                }

                // incrementing k by continuing this loop, because no value of i and j can be equal to target for two numbers. i.e. it will always be less than our target.
                if (nums[n - 1] + nums[n - 2] < target_2num)
                {
                    continue;
                }
                int i = k + 1, j = n - 1;
                while (i < j)
                {
                    // Sum for last two numbers
                    int sum_2num = nums[i] + nums[j];
                    if (sum_2num > target_2num)
                    {
                        j--;

                        // skipping duplicates
                        while (i < j && nums[j] == nums[j + 1])
                        {
                            j--;
                        }
                    }
                    else if (sum_2num < target_2num)
                    {
                        i++;

                        // skipping duplicates
                        while (i < j && nums[i] == nums[i - 1])
                        {
                            i++;
                        }
                    }
                    else
                    {
                        v.push_back({nums[l], nums[k], nums[i++], nums[j--]});

                        // skipping duplicates
                        while (i < j && nums[i] == nums[i - 1])
                        {
                            i++;
                        }
                        while (i < j && nums[j] == nums[j + 1])
                        {
                            j--;
                        }
                    }
                }
            }
        }
        return v;
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
    vector<vector<int>> ans = obj.fourSum(v, t);

    for (int i = 0; i < ans.size(); i++)
    {
        for (auto j : ans[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}