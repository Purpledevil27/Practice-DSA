#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> mymap;
    for (int i = 0; i < m; i++)
    {
        string f, s;
        cin >> f >> s;
        if (f.length() > s.length())
        {
            mymap[f] = s;
        }
        else
        {
            mymap[f] = f;
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        ans += mymap[t];
        ans += " ";
    }
    cout << ans << endl;
    return 0;
}
