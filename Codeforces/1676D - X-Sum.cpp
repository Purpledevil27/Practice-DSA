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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        int max = INT_MIN, smallmax = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                smallmax = v[i][j];
                int x = i, y = j;
                while (x >= 0 && y >= 0 && x < n && y < m)
                {
                    x--;
                    y--;
                    if (x >= 0 && y >= 0 && x < n && y < m)
                    {
                        smallmax += v[x][y];
                    }
                }
                x = i;
                y = j;
                while (x >= 0 && y >= 0 && x < n && y < m)
                {
                    x--;
                    y++;
                    if (x >= 0 && y >= 0 && x < n && y < m)
                    {
                        smallmax += v[x][y];
                    }
                }
                x = i;
                y = j;
                while (x >= 0 && y >= 0 && x < n && y < m)
                {
                    x++;
                    y++;
                    if (x >= 0 && y >= 0 && x < n && y < m)
                    {
                        smallmax += v[x][y];
                    }
                }
                x = i;
                y = j;
                while (x >= 0 && y >= 0 && x < n && y < m)
                {
                    x++;
                    y--;
                    if (x >= 0 && y >= 0 && x < n && y < m)
                    {
                        smallmax += v[x][y];
                    }
                }
                if (smallmax > max)
                {
                    max = smallmax;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}
