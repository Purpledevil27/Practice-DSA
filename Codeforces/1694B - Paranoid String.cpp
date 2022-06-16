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
        ll n, ans;
        string S;
        cin >> n >> S;
        ans = n;
        for (int i = 1; i < n; ++i)
            if (S[i] != S[i - 1])
                ans += i;
        cout << ans << '\n';
    }
    return 0;
}
