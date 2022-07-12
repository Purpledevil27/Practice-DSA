// using upper_bound - Approach #1
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < i + 1)
            {
                v.push_back({a[i], i + 1});
            }
        }
        long long count = 0;
        if (v.size() == 0)
        {
            cout << count << endl;
            continue;
        }
        sort(v.begin(), v.end(), [](pair<int, int> s, pair<int, int> n)
             { return s.first < n.first; });

        for (int i = 0; i < v.size() - 1; i++)
        {
            int u = upper_bound(v.begin(), v.end(), v[i].second, [](int n, pair<int, int> s)
                                { return s.first > n; }) -
                    v.begin();
            count += (v.size() - u);
        }
        cout << count << endl;
    }
    return 0;
}

// Using Prefix-sum - Approach #2
#include <bits/stdc++.h>

using namespace std;
int t, n, a[200005], pref[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pref[i] = pref[i - 1] + (a[i] < i);
            // cout << pref[i] << " ";
            if (a[i] < i)
            {
                cout << i << " " << a[i] << " " << pref[a[i] - 1] << " " << endl;
                ans += pref[a[i] - 1];
            }
        }

        cout << "\n"
             << ans << "\n";
    }
    return 0;
}