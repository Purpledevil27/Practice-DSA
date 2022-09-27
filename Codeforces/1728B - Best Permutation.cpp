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
        if (n % 2 != 0)
        {
            for (int i = n - 3; i >= 2; i--)
            {
                cout << i << " ";
            }
            cout << n - 2 << " " << 1 << " " << n - 1 << " " << n;
        }
        else
        {
            for (int i = n - 2; i >= 1; i--)
            {
                cout << i << " ";
            }
            cout << n - 1 << " " << n;
        }
        cout << endl;
    }
    return 0;
}
