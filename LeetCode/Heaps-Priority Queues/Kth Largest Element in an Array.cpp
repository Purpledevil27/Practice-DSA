// https://leetcode.com/problems/kth-largest-element-in-an-array/

/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:

1 <= k <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Using Quick Select - Approach #1 - O(N)
class Solution
{
    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = nums[start];
        int count = 0;
        for (int i = start + 1; i <= end; i++)
        {
            if (nums[i] <= pivot)
            {
                count++;
            }
        }
        int pivotIndex = start + count;
        swap(nums[start], nums[pivotIndex]);
        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex)
        {
            while (nums[i] <= pivot)
            {
                i++;
            }
            while (nums[j] > pivot)
            {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex)
            {
                swap(nums[i++], nums[j--]);
            }
        }
        return pivotIndex;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int high = n - 1, low = 0, targetIndex = n - k;

        while (high >= low)
        {
            int p = partition(nums, low, high);
            if (p == targetIndex)
            {
                return nums[p];
            }
            else if (p > targetIndex)
            {
                high = p - 1;
            }
            else
            {
                low = p + 1;
            }
        }
        return -1;
    }
};

// Using Priority Queue - Approach #2 - O(nlogn)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

// Using sort function - Approach #3 - O(nlogn)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - k];
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
    cout << obj.findKthLargest(v, t);
    return 0;
}