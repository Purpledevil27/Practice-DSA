#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, m;
        cin >> n >> h >> m;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int th, tm;
            cin >> th >> tm;
            v.push_back({th, tm});
        }

        sort(v.begin(), v.end());
        v.push_back({24 + v[0].first, v[0].second});
        int ans = INT_MAX;

        for (int i = 0; i < v.size(); i++)
        {
            if (((m <= v[i].second && h == v[i].first) || (h < v[i].first)))
            {
                ans = min(ans, -(m - (v[i].first * 60) - (v[i].second) + (h * 60)));
            }
        }
        cout << ans / 60 << " " << ans % 60 << endl;
    }
    return 0;
}