#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
/*
#define N 100000
long long f[N+1];

void fac(){
    f[0] = f[1] = 1;
    for(int i=2;i<N;i++){
        f[i] = (f[i-1]*i)%MOD;
    }
}
*/
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        vector<bool> v(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && s[st.top()] > s[i])
            {
                v[st.top()] = true;
                st.pop();
            }
            st.push(i);
        }
        /*for(int i=0;i<n;i++){
            cout << v[i] << " " << "\n";
        }*/
        vector<int> d(10, 0);
        for (int i = 0; i < n; i++)
        {
            if (v[i] == true)
            {
                // cout << s[i] << "\n";
                int index = min(s[i] - '0' + 1, 9);
                d[index]++;
            }
            else
            {
                // cout << s[i] << "\n";
                d[s[i] - '0']++;
            }
        }
        string ans = "";
        for (int i = 0; i < 10; i++)
        {
            while (d[i])
            {
                ans += (i + '0');
                d[i]--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
