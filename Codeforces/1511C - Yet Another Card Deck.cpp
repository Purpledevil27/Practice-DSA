#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> s1, s2;
    for (int i = n - 1; i >= 0; i--)
    {
        s1.push(a[i]);
    }
    vector<int> ans;
    while (q--)
    {
        int num, count = 1;
        cin >> num;
        while (s1.top() != num)
        {
            count++;
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        s1.pop();
        while (!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }
        s1.push(num);
        ans.push_back(count);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
