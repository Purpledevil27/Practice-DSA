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
        int n = s.length();
        int count = 0, temp = 0;
        int back = n;
        for (int i = n - 1; i >= 0; i--)
        {
            temp++;
            if (s[i] == 'R')
            {
                count = max(temp, count);
                temp = 0;
                back = i + 1;
            }
        }
        if (count == 0)
        {
            count = n + 1;
        }
        cout << max(count, back) << endl;
    }
    return 0;
}
