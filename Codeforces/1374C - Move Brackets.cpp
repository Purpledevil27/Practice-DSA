#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        int bal = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                ++bal;
            else
            {
                --bal;
                if (bal < 0)
                {
                    bal = 0;
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> rem;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                rem.push(s[i]);
            }
            else if (s[i] == ')' && rem.empty())
            {
                rem.push(s[i]);
            }
            else
            {
                if (rem.top() == '(')
                {
                    rem.pop();
                }
                else
                {
                    rem.push(s[i]);
                }
            }
        }
        if (rem.empty())
        {
            cout << 0 << endl;
        }
        else
        {
            cout << rem.size() / 2 << endl;
        }
    }
}
*/