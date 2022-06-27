// https://leetcode.com/problems/maximum-score-of-spliced-array/

/*You are given two 0-indexed integer arrays nums1 and nums2, both of length n.

You can choose two integers left and right where 0 <= left <= right < n and swap the subarray nums1[left...right] with the subarray nums2[left...right].

For example, if nums1 = [1,2,3,4,5] and nums2 = [11,12,13,14,15] and you choose left = 1 and right = 2, nums1 becomes [1,12,13,4,5] and nums2 becomes [11,2,3,14,15].
You may choose to apply the mentioned operation once or not do anything.

The score of the arrays is the maximum of sum(nums1) and sum(nums2), where sum(arr) is the sum of all the elements in the array arr.

Return the maximum possible score.

A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).

Example 1:

Input: nums1 = [60,60,60], nums2 = [10,90,10]
Output: 210
Explanation: Choosing left = 1 and right = 1, we have nums1 = [60,90,60] and nums2 = [10,60,10].
The score is max(sum(nums1), sum(nums2)) = max(210, 80) = 210.

Example 2:

Input: nums1 = [20,40,20,70,30], nums2 = [50,20,50,40,20]
Output: 220
Explanation: Choosing left = 3, right = 4, we have nums1 = [20,40,20,40,20] and nums2 = [50,20,50,70,30].
The score is max(sum(nums1), sum(nums2)) = max(140, 220) = 220.

Example 3:

Input: nums1 = [7,11,13], nums2 = [1,1,1]
Output: 31
Explanation: We choose not to swap any subarray.
The score is max(sum(nums1), sum(nums2)) = max(31, 3) = 31.

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
1 <= nums1[i], nums2[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 to Kadane Algorithm
class Solution
{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int sum1 = 0, sum2 = 0, res1 = 0, res2 = 0, md1 = 0, md2 = 0;
        sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int i = 0; i < nums2.size(); i++)
        {
            md1 = max(nums2[i] - nums1[i], md1 + nums2[i] - nums1[i]);
            res1 = max(res1, md1);
            md2 = max(nums1[i] - nums2[i], md2 + nums1[i] - nums2[i]);
            res2 = max(res2, md2);
        }
        return max(sum1 + res1, sum2 + res2);
    }
};

// Another Approach to Kadane Algorithm
class Solution
{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int sum1 = 0, sum2 = 0;
        sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int max_so_far_1 = INT_MIN, max_so_far_2 = INT_MIN, max_ending_here_1 = 0, max_ending_here_2 = 0;
        // int start = 0, end = 0, s = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            max_ending_here_1 += nums2[i] - nums1[i];
            max_ending_here_2 += nums1[i] - nums2[i];
            if (max_so_far_1 < max_ending_here_1)
            {
                max_so_far_1 = max_ending_here_1;
                // start = s;
                // end = i;
            }
            if (max_so_far_2 < max_ending_here_2)
            {
                max_so_far_2 = max_ending_here_2;
                // start = s;
                // end = i;
            }

            if (max_ending_here_1 < 0)
            {
                max_ending_here_1 = 0;
                // s = i + 1;
            }

            if (max_ending_here_2 < 0)
            {
                max_ending_here_2 = 0;
                // s = i + 1;
            }
        }
        return max(sum1 + max_so_far_1, sum2 + max_so_far_2);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums1, nums2;
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    Solution obj;
    cout << obj.maximumsSplicedArray(nums1, nums2);
    return 0;
}