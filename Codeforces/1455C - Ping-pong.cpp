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
        int x, y;
        cin >> x >> y;
        cout << max(0, x - 1) << " " << max(y, 0) << endl;
    }
    return 0;
}
