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

        vector<int> a(n);
        int s = -1;
        bool div5 = false;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            a[i] = p;
            if (a[i] % 5 == 0)
            {
                div5 = true;
            }
        }
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        unordered_set<int> se(a.begin(), a.end());
        if (se.size() == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        if (div5)
        {
            unordered_map<int, int> m;
            for (int i = 0; i < n; i++)
            {
                m[a[i]]++;
                if (a[i] % 5 != 0)
                {
                    cout << "NO" << endl;
                    goto finale;
                }
                if (m.size() > 2)
                {
                    cout << "NO" << endl;
                    goto finale;
                }
            }
            priority_queue<int> pq;
            for (auto it : m)
            {
                pq.push(it.first);
            }
            int maxi = pq.top();
            pq.pop();
            int mini = pq.top();
            if (maxi - mini != 5 || maxi % 10 != 0)
            {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            int t = a[i];
            while ((t % 10) % 2 != 0)
            {
                t += (t % 10);
            }
            int m1 = t % 10;
            if (m1 == 2 || m1 == 4 || m1 == 8)
            {
                int tt = t / 10;
                int m2 = tt % 10;
                if (m2 % 2 == 0)
                {
                    if (s == 0)
                    {
                        cout << "NO" << endl;
                        goto finale;
                    }
                    s = 1;
                }
                else
                {
                    if (s == 1)
                    {
                        cout << "NO" << endl;
                        goto finale;
                    }
                    s = 0;
                }
            }
            else if (m1 == 6)
            {
                int tt = t / 10;
                int m2 = tt % 10;
                if (m2 % 2 == 0)
                {
                    if (s == 1)
                    {
                        cout << "NO" << endl;
                        goto finale;
                    }
                    s = 0;
                }
                else
                {
                    if (s == 0)
                    {
                        cout << "NO" << endl;
                        goto finale;
                    }
                    s = 1;
                }
            }
        }
        cout << "YES" << endl;
    finale:
        continue;
    }
    return 0;
}
