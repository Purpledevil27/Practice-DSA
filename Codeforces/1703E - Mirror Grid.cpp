#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> grid;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            grid.push_back(s);
        }
        int ans = 0;
        int size = n, start = 0, end = n;
        while (size > 1)
        {
            int unique_ele = size - 1;
            vector<pair<int, int>> dp(unique_ele);
            int i = start, j = start, step = 4 * unique_ele;
            while (step > 0)
            {
                while (j < end && step > 0)
                {
                    // cout << grid[i][j] << " ";
                    if (grid[i][j] == '0')
                    {
                        dp[step % unique_ele].first++;
                    }
                    else
                    {
                        dp[step % unique_ele].second++;
                    }
                    j++;
                    step--;
                }
                j--;
                i++;
                while (i < end && step > 0)
                {
                    // cout << grid[i][j] << " ";
                    if (grid[i][j] == '0')
                    {
                        dp[step % unique_ele].first++;
                    }
                    else
                    {
                        dp[step % unique_ele].second++;
                    }
                    i++;
                    step--;
                }
                i--;
                j--;
                while (j >= start && step > 0)
                {
                    // cout << grid[i][j] << " ";
                    if (grid[i][j] == '0')
                    {
                        dp[step % unique_ele].first++;
                    }
                    else
                    {
                        dp[step % unique_ele].second++;
                    }
                    j--;
                    step--;
                }
                j++;
                i--;
                while (i > start && step > 0)
                {
                    // cout <<endl<< i <<" "<< j <<endl;
                    // cout << grid[i][j] << " ";
                    if (grid[i][j] == '0')
                    {
                        dp[step % unique_ele].first++;
                    }
                    else
                    {
                        dp[step % unique_ele].second++;
                    }
                    i--;
                    step--;
                }
            }
            for (auto i : dp)
            {
                // cout<< i.first << " " << i.second << endl;
                ans += (min(i.first, i.second));
            }
            size -= 2;
            start++;
            end--;
        }
        cout << ans << endl;
    }
    return 0;
}
