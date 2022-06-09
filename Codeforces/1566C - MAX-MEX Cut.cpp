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
        string t, y;
        cin >> t >> y;

        int i = 0, count = 0;
        while (i < n)
        {
            if ((t[i] == '0' && y[i] == '1') || (t[i] == '1' && y[i] == '0'))
            {
                count += 2;
                i++;
            }
            else if ((t[i] == '0' && y[i] == '0'))
            {
                while (i < n && (t[i] != '1' && y[i] != '1'))
                {
                    i++;
                    count++;
                }
                if (i < n && (t[i] == '0' && y[i] == '1') || (t[i] == '1' && y[i] == '0'))
                {
                    count += 2;
                    i++;
                }
                else if (i < n && (t[i] == '1' && y[i] == '1'))
                {
                    count++;
                    i++;
                }
            }
            else if (t[i] == '1' && y[i] == '1')
            {
                while (i < n && (t[i] != '0' && y[i] != '0'))
                {
                    i++;
                }
                if (i < n)
                {
                    count += 2;
                    i++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
