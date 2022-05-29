#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n, m;
        cin >> x >> n >> m;

        while (x > 20 && n > 0)
        {
            x = x / 2 + 10;
            n--;
        }
        while (x > 0 && m > 0)
        {
            x = x - 10;
            m--;
        }
        if (x <= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
