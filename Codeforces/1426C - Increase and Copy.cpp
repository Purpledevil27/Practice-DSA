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
        int part1 = sqrt(n);
        double part2 = ceil((double)(n - part1) / (double)part1);
        int ans = part1 - 1 + part2;
        cout << ans << endl;
    }
    return 0;
}
