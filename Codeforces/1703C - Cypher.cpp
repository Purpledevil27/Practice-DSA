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
        int curr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> curr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            string s;
            cin >> s;
            for (int k = 0; k < j; k++)
            {
                if (s[k] == 'U')
                {
                    curr[i] = (curr[i] - 1);
                    if (curr[i] < 0)
                    {
                        curr[i] += 10;
                    }
                }
                else
                {
                    curr[i] = (curr[i] + 1) % 10;
                }
            }
        }
        for (auto i : curr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
