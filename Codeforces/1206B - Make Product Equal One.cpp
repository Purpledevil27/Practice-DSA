#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int neg = 0, pos = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            pos++;
        }
        else if (a[i] == 0)
        {
            zero++;
        }
        else
        {
            neg++;
        }
    }
    sort(a, a + n);
    long long coin = 0;
    if (neg % 2 != 0 && zero == 0)
    {
        coin += (1 - a[0]);
        for (int i = 1; i < neg; i++)
        {
            coin += (-1 - a[i]);
        }
    }
    else
    {
        for (int i = 0; i < neg; i++)
        {
            coin += (-1 - a[i]);
        }
    }
    for (int i = neg; i < n; i++)
    {
        if (a[i] == 0)
        {
            coin += 1;
        }
        else
        {
            coin += a[i] - 1;
        }
    }
    cout << coin;
    return 0;
}
