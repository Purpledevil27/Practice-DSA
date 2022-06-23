// https://leetcode.com/problems/top-k-frequent-elements/

/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/

#include <bits/stdc++.h>
using namespace std;

// Using Hashmap and Pair Priority queue - Approach #1
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        // Using Priority Queue of pairs ordering by first element
        // (first elements is frequency of a distinct element from the nums & and second element is that distinct element itself)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int>::iterator it = m.begin();
        // pushing the random first k elements from the map into the pq
        for (int i = 0; i < k; i++)
        {
            pq.push({it->second, it->first});
            it++;
        }
        // iterating till the end of the map
        while (it != m.end())
        {
            pair<int, int> top = pq.top();
            // checking if more frequent element is present in map than top(min) element in pq
            if (it->second > top.first)
            {
                pq.pop();
                pq.push({it->second, it->first});
            }
            it++;
        }
        // finally, pushing the top frequent key into the answer
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Using Bucket Sort - Approach #2
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        vector<int> ans;
        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &i : nums)
        {
            m[i]++;
        }
        // Pushing the element into their frequency number
        for (const auto &it : m)
        {
            bucket[it.second].push_back(it.first);
        }
        // such that now we start iterating from the back of the vector and break/return when the k most frequent elements are found
        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < bucket[i].size(); j++)
            {
                ans.push_back(bucket[i][j]);
                if (ans.size() == k)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};

// Drivers Code
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
    vector<int> ans = obj.topKFrequent(v, t);
    for (auto j : ans)
    {
        cout << j << " ";
    }
    return 0;
}