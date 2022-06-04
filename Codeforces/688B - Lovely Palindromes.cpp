#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans = s;
    reverse(s.begin(), s.end());
    ans = ans + s;
    cout << ans;
    return 0;
}
