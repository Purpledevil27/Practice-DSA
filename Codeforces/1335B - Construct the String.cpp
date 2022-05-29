#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        char c = 97;
        string s = "";
        while (c - 97 < b)
        {
            s += c;
            c++;
        }
        c = 97;
        while (s.length() != n)
        {
            s += c;
            c++;
            if (c - 97 == b)
            {
                c = 97;
            }
        }
        cout << s << endl;
    }
    return 0;
}
