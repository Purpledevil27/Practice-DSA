#include <bits/stdc++.h>
using namespace std;

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
        sort(a, a + n, greater<int>());
        vector<int> ans(n - 1, 0);
        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }
        int sub = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int t = a[i] - sub;
            ans.push_back(t);
            sub += t;
        }
        // cout << " ans ";
        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
    return 0;
}
