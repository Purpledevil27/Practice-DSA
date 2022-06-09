#include <bits/stdc++.h>
using namespace std;

#define ll long long
// Using Sliding Window
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            s += ch;
        }
        int w = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'W')
            {
                w++;
            }
        }
        int min = w;
        int i = 0, j = k;
        for (; j < n; j++)
        {
            if (s[i] == 'B' && s[j] == 'W')
            {
                w++;
            }
            else if (s[i] == 'W' && s[j] == 'B')
            {
                w--;
            }
            if (min > w)
            {
                min = w;
            }
            i++;
        }
        cout << min << endl;
    }
    return 0;
}
