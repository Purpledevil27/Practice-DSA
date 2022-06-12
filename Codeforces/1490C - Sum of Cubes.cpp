#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1000000000000;
unordered_set<ll> cubes;

void precalc()
{
    for (ll i = 1; i * i * i <= N; i++)
    {
        cubes.insert(i * i * i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precalc();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 1; i * i * i <= n; i++)
        {
            if (cubes.count(n - (i * i * i)))
            {
                cout << "YES" << endl;
                goto label;
            }
        }
        cout << "NO" << endl;
    label:
        continue;
    }
    return 0;
}
