#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> m;
    vector<int> inc;
    vector<int> dec;
    for (int i = 0; i < n; i++)
    {
        if (m[a[i]] == 0)
        {
            inc.push_back(a[i]);
            m[a[i]]++;
        }
        else if (m[a[i]] == 1)
        {
            dec.push_back(a[i]);
            m[a[i]]++;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    int si = inc.size();
    sort(inc.begin(), inc.end());
    cout << inc.size() << endl;
    for (auto i : inc)
    {
        cout << i << " ";
    }
    cout << endl;
    int sd = dec.size();
    sort(dec.begin(), dec.end(), greater<int>());
    cout << dec.size() << endl;
    for (auto i : dec)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
