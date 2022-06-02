#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long moves = 0;
        long long eight = 8;
        for (int i = 1; i <= n / 2; i++)
        {
            moves += (i * eight);
            eight += 8;
        }
        cout << moves << endl;
    }
    return 0;
}
