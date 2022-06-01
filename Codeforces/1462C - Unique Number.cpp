#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int ans = 0;
        if (x > 45)
        {
            cout << -1 << endl;
            continue;
        }
        int p = 9;
        while (x > 0)
        {
            if (x < 10 && x < p)
            {
                break;
            }
            ans += round(pow(10, 9 - p) * p);
            x -= p--;
        }
        ans += pow(10, 9 - p) * x;
        cout << ans << endl;
    }
    return 0;
}
