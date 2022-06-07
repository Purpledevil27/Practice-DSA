#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    ll m;
    cin >> n >> m;
    ll room_in_dom[n];
    for (int i = 0; i < n; i++)
    {
        cin >> room_in_dom[i];
    }
    ll letter[m];
    for (int i = 0; i < m; i++)
    {
        cin >> letter[i];
    }

    ll a[n];
    a[0] = room_in_dom[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + room_in_dom[i];
    }

    for (int i = 0; i < m; i++)
    {
        int index = lower_bound(a, a + n, letter[i]) - a;
        // cout << a[index] << " " << letter[i] << endl;
        if (index == 0)
        {
            cout << index + 1 << " " << letter[i] << endl;
        }
        else if (index == n)
        {
            cout << index << " " << letter[i] - a[index - 1];
        }
        else
        {
            cout << index + 1 << " " << -a[index - 1] + letter[i] << endl;
        }
    }

    return 0;
}
