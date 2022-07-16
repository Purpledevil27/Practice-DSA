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
        long long sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += a[i];
        }
        long long z = 0, i = 0;
        for (; i < n; i++)
        {
            if (a[i] != 0)
                break;
        }
        for (; i < n - 1; i++)
        {
            if (a[i] == 0)
                z += 1;
        }
        if (sum != 0)
            cout << sum + z << endl;
        else
        {
            cout << sum << endl;
        }
    }
    return 0;
}
