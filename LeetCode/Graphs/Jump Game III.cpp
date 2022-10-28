// https://leetcode.com/problems/jump-game-iii/

/*Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3

Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
Explanation:
One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3

Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

Constraints:
1 <= arr.length <= 5 * 1^04
0 <= arr[i] < arr.length
0 <= start < arr.length
*/

#include <bits/stdc++.h>
using namespace std;

// Using BFS
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        // return true if the starts at value 0 only
        if (arr[start] == 0)
            return true;

        queue<int> q;
        int n = arr.size();
        // create an array for visited index
        vector<int> v(arr.size(), false);
        // start from the 'start' index
        q.push(start);
        // mark it visited
        v[start] = true;
        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (i + arr[i] < n && !v[i + arr[i]])
            {
                // return true if the next element value is 0
                if (arr[i + arr[i]] == 0)
                {
                    return true;
                }
                else
                {
                    // else push it in the queue and mark it visited
                    q.push(i + arr[i]);
                    v[i + arr[i]] = true;
                }
            }
            if (i - arr[i] >= 0 && !v[i - arr[i]])
            {
                // return true if the next element value is 0
                if (arr[i - arr[i]] == 0)
                {
                    return true;
                }
                else
                {
                    // else push it in the queue and mark it visited
                    q.push(i - arr[i]);
                    v[i - arr[i]] = true;
                }
            }
        }
        // we cannot step onto a index with value 0. hence, return false
        return false;
    }
};