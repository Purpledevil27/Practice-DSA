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
        int ans = -1, m = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (m <= a[i])
            {
                m = max(m, a[i]);
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
