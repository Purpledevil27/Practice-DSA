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
        int e = 0, o = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }
        int oo = o, ee = e;
        sort(a, a + n);
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] == 1)
            {
                oo--;
                ee--;
                if ((oo % 2 == 0 && ee % 2 == 0) || (o % 2 == 0 && e % 2 == 0))
                {
                    cout << "YES" << endl;
                    goto label;
                }
                else
                {
                    cout << "NO" << endl;
                    goto label;
                }
                i++;
            }
        }
        if ((o % 2 == 0 && e % 2 == 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    label:
        continue;
    }
    return 0;
}
