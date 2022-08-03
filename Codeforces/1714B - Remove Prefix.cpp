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
        unordered_map<int, int> m;
        for (int i = n - 1; i >= 0; i--)
        {
            if (m.count(a[i]))
            {
                cout << i + 1 << endl;
                goto finale;
            }
            m[a[i]]++;
        }
        cout << 0 << endl;
    finale:
        continue;
    }
    return 0;
}
