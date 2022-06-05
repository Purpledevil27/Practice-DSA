// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull

/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or
twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:

Input: nums = [1,1,2]
Output: [1]

Example 3:

Input: nums = [1]
Output: []

Constraints:

n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= n
Each element in nums appears once or twice.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        /*ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);*/
        vector<int> ans;
        for (auto i : nums)
        {
            if (nums[abs(i) - 1] < 0)
            {
                ans.push_back(abs(i));
            }
            nums[abs(i) - 1] *= -1;
        }
        return ans;
    }
};

// Using Hashmap
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto i : nums)
        {
            if (m[i] > 0 && m[i] < 2)
            {
                ans.push_back(i);
            }
            m[i]++;
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
    vector<int> v2 = obj.findDuplicates(v);
    for (auto i : v2)
    {
        cout << i << " ";
    }
    return 0;
}