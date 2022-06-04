// https://leetcode.com/problems/sort-colors/
// Using Dutch national flag Algorithm
// https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/
// https://en.wikipedia.org/wiki/In-place_algorithm

/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are
adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int mid = 0, low = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
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
    obj.sortColors(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}