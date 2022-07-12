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
        int n, count = 0;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            if (m[s[i]] == 0)
            {
                count += 2;
                m[s[i]]++;
            }
            else
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
