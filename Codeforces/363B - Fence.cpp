#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += a[i - 1];
    }
    int j = 1, smallsum = sum;
    int ans = 1;
    for (int i = k + 1; i <= n; i++)
    {
        smallsum += (a[i - 1] - a[j - 1]);
        j++;
        if (smallsum < sum)
        {
            sum = smallsum;
            ans = i - k + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
