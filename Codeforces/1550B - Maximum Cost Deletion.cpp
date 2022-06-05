#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int m = distance(s.begin(), unique(s.begin(), s.end()));
        // int m = unique(s.begin(), s.end()) -s.begin();
        int ans = a * n + max(b * n, (m / 2 + 1) * b);
        cout << ans << endl;
    }
    return 0;
}