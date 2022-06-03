#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int k = nums[0];
        int step = 1;
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] != k)
            {
                nums[step++] = nums[i];
                k = nums[i];
            }
        }
        return step;
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
    int ans = obj.removeDuplicates(v);
    for (int i = 0; i < ans; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}