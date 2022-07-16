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
        int n, x;
        cin >> n >> x;
        int size = 2 * n;
        int a[size];
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + size);
        int i = 0, j = n;
        bool ans = true;
        for (int k = 0; k < n; k++)
        {
            if (a[j + k] - a[i + k] < x)
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
