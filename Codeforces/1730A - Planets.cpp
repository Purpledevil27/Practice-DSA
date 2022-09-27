#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
/*
#define N 100000
long long f[N+1];

void fac(){
    f[0] = f[1] = 1;
    for(int i=2;i<N;i++){
        f[i] = (f[i-1]*i)%MOD;
    }
}
*/
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int a[n];
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        int ans = 0;
        for (auto &i : m)
        {
            if (i.second >= c)
            {
                ans += c;
            }
            else
            {
                ans += i.second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
