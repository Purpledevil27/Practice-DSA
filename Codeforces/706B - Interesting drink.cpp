#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q, n, ans, coins;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    sort(a, a + n);
    while (q--)
    {
        cin >> coins;
        ans = upper_bound(a, a + n, coins) - a;
        cout << ans << endl;
    }
    return 0;
}