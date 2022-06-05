#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 0;
    while (i <= (2 * n + 1) / 2)
    {
        for (int j = 0; j < ((4 * n + 1) - 4 * i) / 2; j++)
        {
            cout << " ";
        }
        int k = 0, p = 0;
        while (k < (4 * i + 1) / 2)
        {
            if (k % 2 == 0)
            {
                cout << p++;
                k++;
            }
            else
            {
                k++;
                cout << " ";
            }
        }
        cout << p;
        while (k)
        {
            if (k % 2 == 0)
            {
                cout << " ";
                k--;
            }
            else
            {
                cout << --p;
                k--;
            }
        }
        i++;
        cout << endl;
    }
    i -= 2;

    while (i >= 0)
    {
        for (int j = 0; j < ((4 * n + 1) - 4 * i) / 2; j++)
        {
            cout << " ";
        }
        int k = 0, p = 0;
        while (k < (4 * i + 1) / 2)
        {
            if (k % 2 == 0)
            {
                cout << p++;
                k++;
            }
            else
            {
                k++;
                cout << " ";
            }
        }
        cout << p;
        while (k)
        {
            if (k % 2 == 0)
            {
                cout << " ";
                k--;
            }
            else
            {
                cout << --p;
                k--;
            }
        }
        i--;
        cout << endl;
    }

    return 0;
}
