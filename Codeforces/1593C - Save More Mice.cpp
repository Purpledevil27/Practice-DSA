#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[k];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        sort(a, a + k, greater<int>());
        int step = 0, count = 0;
        for (int i = 0; i < k; i++)
        {

            if (step >= a[i])
            {
                break;
            }
            step += (n - a[i]);
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
