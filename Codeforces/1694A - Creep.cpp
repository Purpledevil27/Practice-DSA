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
        int z, o;
        cin >> z >> o;
        string s = "";
        if (z <= o)
        {
            while (z != 0)
            {
                s += '01';
                z--;
                o--;
            }
            while (o != 0)
            {
                s += '1';
                o--;
            }
        }
        else
        {
            while (o != 0)
            {
                s += '01';
                z--;
                o--;
            }
            while (z != 0)
            {
                s += '0';
                z--;
            }
        }
        cout << s << endl;
    }
    return 0;
}
