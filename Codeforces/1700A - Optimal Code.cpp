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
        int n, m;
        cin >> n >> m;
        long long ans = (m * (m + 1)) / 2;
        for (int i = 2; i <= n; i++)
        {
            ans += m * i;
        }
        cout << ans << endl;
    }
    return 0;
}
