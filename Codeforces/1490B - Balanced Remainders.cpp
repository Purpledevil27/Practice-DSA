#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 3 == 0)
            {
                c0++;
            }
            else if (a[i] % 3 == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        // cout << c0 <<c1<<c2<<endl;
        int ans = 0;
        while (c0 != c1 || c2 != c1 || c2 != c0)
        {
            if (c0 < c2)
            {
                c0++;
                c2--;
                ans++;
            }
            else if (c1 < c0)
            {
                c1++;
                c0--;
                ans++;
            }
            else if (c2 < c1)
            {
                c2++;
                c1--;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
