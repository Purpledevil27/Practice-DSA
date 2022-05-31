#include <bits/stdc++.h>
using namespace std;
/*
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, b%a);
}
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int e[n] = {0}, o[n] = {0};
        int ei = 0, oi = 0;
        int a[n] = {0};

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                e[ei++] = a[i];
            }
            else
            {
                o[oi++] = a[i];
            }
        }

        int index = 0;

        for (int i = 0; i < ei; i++)
        {
            a[index++] = e[i];
        }
        for (int i = 0; i < oi; i++)
        {
            a[index++] = o[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(a[i], 2 * a[j]) > 1)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
