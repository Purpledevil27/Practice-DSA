#include <iostream>
using namespace std;

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        int l, r, a;
        cin >> l >> r >> a;

        int q1 = l / a;
        int q2 = r / a;
        int ans = 0;

        if (q1 == q2)
        {
            ans = q2 + r % a;
        }
        else
        {
            if ((r + 1) % a == 0)
            {
                ans = q2 + a - 1;
            }
            else
            {
                ans = q2 - 1 + a - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
