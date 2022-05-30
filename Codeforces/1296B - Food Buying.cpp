#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        int count = s;
        int x = s / 10;
        int rem = s % 10;
        while (rem + x >= 10)
        {
            count += x;
            int t = rem + x;
            x = t / 10;
            rem = t % 10;
        }
        count += x;
        cout << count << endl;
    }
    return 0;
}
