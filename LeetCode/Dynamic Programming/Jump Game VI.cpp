// https://leetcode.com/problems/jump-game-vi/

/*You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array.
That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

Example 3:

Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0

Constraints:
1 <= nums.length, k <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        // return if nums size is 1
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();

        // dp to store the max score we can get from a index 'i' to the end of the array
        vector<int> dp(n, 0);
        // Using a max priority queue to store the max dp values and their index
        priority_queue<pair<int, int>> pq;
        for (int i = n - 1; i >= 0; i--)
        {
            // pop elemnts until the top dp values index is not in the range of i+k
            while (!pq.empty() && pq.top().second > i + k)
            {
                pq.pop();
            }
            int max = 0;
            if (!pq.empty())
                max = pq.top().first;
            // maximum score from i to the end
            dp[i] = max + nums[i];
            // pushing the dp value into the queue
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};