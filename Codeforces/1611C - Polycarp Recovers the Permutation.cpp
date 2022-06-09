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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[0] != n && a[n - 1] != n)
        {
            cout << -1 << endl;
            continue;
        }
        int i = 0, j = n - 1;
        deque<int> ans;
        if (a[0] < a[n - 1])
        {
            j--;
            ans.push_back(a[n - 1]);
        }
        else
        {
            i++;
            ans.push_back(a[0]);
        }
        while (i <= j)
        {
            if (a[i] < ans.back())
            {
                ans.push_front(a[i]);
                i++;
            }
            else if (a[j] < ans.front())
            {
                ans.push_back(a[j]);
                j--;
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
