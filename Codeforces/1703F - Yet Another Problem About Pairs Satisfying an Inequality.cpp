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