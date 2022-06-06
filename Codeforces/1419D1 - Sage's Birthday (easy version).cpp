#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans[n] = {0};
    sort(a, a + n);
    int step = 0;
    for (int i = 1; i < n; i += 2)
    {
        ans[i] = a[step++];
    }
    for (int i = 0; i < n; i += 2)
    {
        ans[i] = a[step++];
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
        {
            // cout << i<< endl;
            count++;
        }
    }
    cout << count << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
