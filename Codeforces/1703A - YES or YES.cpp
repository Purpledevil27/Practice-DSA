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
        string s;
        cin >> s;
        if ((s[0] == 'Y' || s[0] == 'y') && (s[1] == 'e' || s[1] == 'E') && (s[2] == 'S' || s[2] == 's'))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
