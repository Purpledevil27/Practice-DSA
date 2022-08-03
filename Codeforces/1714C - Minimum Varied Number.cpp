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
        if (n <= 9)
        {
            cout << n << endl;
            continue;
        }
        string ans = "";
        int c = 9;
        while (n > 9 || n >= c)
        {
            if (n <= 0)
            {
                goto finale;
            }
            n -= c;
            ans += (c + '0');
            c--;
        }
        if (n != 0)
            ans += (n + '0');
    finale:
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
