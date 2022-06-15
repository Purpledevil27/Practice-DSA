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
        int d = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (m.count(a[i]) == 0)
            {
                m[a[i]]++;
                d++;
            }
        }
        if ((d % 2 == 0 && n % 2 == 0) || (d % 2 == 1 && n % 2 == 1))
        {
            cout << d << endl;
        }
        else
        {
            cout << d - 1 << endl;
        }
    }
    return 0;
}
