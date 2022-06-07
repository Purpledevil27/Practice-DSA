#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n - 1, vector<int>(2));
        int t = n;
        int index = 0;
        for (int i = n; i > 1; i--)
        {
            v[index][0] = i - 1;
            v[index++][1] = t;
            t = (t + i) / 2;
        }
        cout << t << endl;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto p : v[i])
            {
                cout << p << " ";
            }
            cout << endl;
        }
    }
    return 0;
}