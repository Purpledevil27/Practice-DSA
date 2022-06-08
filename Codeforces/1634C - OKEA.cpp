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
        int n, k;
        cin >> n >> k;
        if (k == 1)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {

                cout << i + 1 << endl;
            }
            continue;
        }
        int even = 2, odd = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i % 2 == 0)
                {
                    // cout << odd<<" ";
                    odd += 2;
                }
                else
                {
                    // cout << even<< " ";
                    even += 2;
                }
            }
        }
        odd -= 2;
        even -= 2;
        if (odd > n * k || even > n * k)
        {
            cout << "NO" << endl;
        }
        else
        {
            even = 2;
            odd = 1;
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (i % 2 == 0)
                    {
                        cout << odd << " ";
                        odd += 2;
                    }
                    else
                    {
                        cout << even << " ";
                        even += 2;
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
