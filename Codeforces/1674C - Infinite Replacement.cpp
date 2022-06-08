// https://www.geeksforgeeks.org/string-find-in-cpp/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        if (m > 1 && t.find('a') != string::npos)
        {
            cout << -1 << endl;
            continue;
        }
        else if (m >= 1 && t.find('a') == string ::npos)
        {
            unsigned long long x = 1;
            for (int i = 0; i < n; i++)
            {
                x *= 2;
            }
            cout << x << endl;
            continue;
        }
        else if (m == 1 && t.find('a') != string::npos)
        {
            cout << 1 << endl;
            continue;
        }
    }
    return 0;
}
