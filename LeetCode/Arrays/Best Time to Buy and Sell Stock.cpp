#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int min = prices[0];
        int maxdiff = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            if (min >= prices[i])
            {
                min = prices[i];
            }
            else
            {
                if (prices[i] - min > maxdiff)
                {
                    maxdiff = prices[i] - min;
                }
            }
        }
        if (maxdiff == INT_MIN)
        {
            maxdiff = 0;
        }
        return maxdiff;
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
    cout << obj.maxProfit(v);

    return 0;
}