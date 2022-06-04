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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        sort(a, a + n);
        for (int i = n; i > 0; i--)
        {
            if (i >= a[i - 1])
            {
                ans = i;
                break;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}