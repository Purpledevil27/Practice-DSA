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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> dp(n, INT_MIN);
        int sum = 0, ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            sum = 0;
            int index = i;
            while (index < n)
            {
                if (dp[index] != INT_MIN)
                {
                    sum += dp[index];
                    break;
                }
                sum += a[index];
                index += a[i];
            }
            dp[i] = sum;
            ans = max(ans, sum);
        }

        cout << ans << endl;
    }
    return 0;
}
