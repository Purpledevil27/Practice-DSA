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
        int a[n] = {0};
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        int ans = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1] && a[i] == max)
            {
                ans = i;
                break;
            }
            if (a[i + 1] > a[i] && a[i + 1] == max)
            {
                ans = i + 1;
                break;
            }
        }
        if (ans >= 0)
            cout << ans + 1 << endl;
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
