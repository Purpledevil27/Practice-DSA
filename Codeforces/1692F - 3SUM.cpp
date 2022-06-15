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
        int nn;
        cin >> nn;
        int a[nn];
        for (int i = 0; i < nn; i++)
        {
            cin >> a[i];
        }
        vector<int> n;
        unordered_map<int, int> m;
        for (int i = 0; i < nn; i++)
        {
            int num = a[i] % 10;
            if (m[num] < 4)
            {
                m[num]++;
                n.push_back(num);
            }
        }
        int size = n.size();
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                for (int k = j + 1; k < size; k++)
                {
                    int temp = n[i] + n[j] + n[k];
                    if (temp % 10 == 3)
                    {
                        cout << "YES" << endl;
                        goto label;
                    }
                }
            }
        }
        cout << "NO" << endl;
    label:
        continue;
    }
    return 0;
}
