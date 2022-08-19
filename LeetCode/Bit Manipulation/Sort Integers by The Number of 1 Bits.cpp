// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

/*You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

Constraints:
1 <= arr.length <= 500
0 <= arr[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    vector<int> sortByBits(vector<int> &a)
    {
        vector<vector<int>> v(15);

        for (int i = 0; i < a.size(); i++)
        {
            int s = __builtin_popcount(a[i]);
            v[s].push_back(a[i]);
        }

        vector<int> ans;
        for (auto &i : v)
        {
            sort(i.begin(), i.end());
            for (auto &j : i)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        auto comp = [](int i, int j)
        {
            int i_b = __builtin_popcount(i);
            int j_b = __builtin_popcount(j);
            return (i_b == j_b) ? i < j : i_b < j_b;
        };
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};