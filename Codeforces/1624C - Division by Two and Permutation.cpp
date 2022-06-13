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
        unordered_map<int, int> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= n)
            {
                m[a[i]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int j = a[i];
            if (j > n || (j <= n && m[j]-- > 1))
            {
                while (j != 1)
                {
                    j /= 2;
                    if (j <= n && m.count(j) == 0)
                    {
                        m[j]++;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (m.count(i) == 0)
            {
                cout << "NO" << endl;
                goto finale;
            }
        }
        cout << "YES" << endl;
    finale:
        continue;
    }
    return 0;
}
