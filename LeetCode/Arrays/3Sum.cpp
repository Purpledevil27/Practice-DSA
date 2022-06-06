// https://leetcode.com/problems/3sum/

/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Example 3:

Input: nums = [0]
Output: []


Constraints:

0 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> v;

        sort(nums.begin(), nums.end());
        for (int k = 0; k < n - 2; k++)
        {
            if (k != 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            int i = k + 1, j = n - 1;

            while (i < j && nums[j] >= 0)
            {
                int temp = nums[k] + nums[i] + nums[j];
                if (temp < 0)
                {
                    i++;
                }
                else if (temp > 0)
                {
                    j--;
                }
                else
                {
                    v.push_back({nums[i++], nums[k], nums[j--]});
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
        return v;
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
    vector<vector<int>> ans = obj.threeSum(v);

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