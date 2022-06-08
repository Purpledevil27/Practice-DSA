// https://www.geeksforgeeks.org/deque-cpp-stl/

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
        deque<int> v;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            if (i == 0)
            {
                v.push_back(k);
                continue;
            }
            if (k <= v[0])
            {
                v.push_front(k);
            }
            else
            {
                v.push_back(k);
            }
        }
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
