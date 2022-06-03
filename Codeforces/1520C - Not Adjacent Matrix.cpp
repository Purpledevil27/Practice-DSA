#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        vector<pair<int, int>> mat;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    pair<int, int> p = make_pair(i, j);
                    mat.push_back(p);
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if ((i + j) % 2 != 0)
                {
                    pair<int, int> p = make_pair(i, j);
                    mat.push_back(p);
                }
            }
        }
        int arr[n][n];
        for (int i = 0; i < (n * n); i++)
        {
            pair<int, int> p = mat.back();
            // cout << p.first << p.second << endl;
            mat.pop_back();
            arr[p.first - 1][p.second - 1] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
