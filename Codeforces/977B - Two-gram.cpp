#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        int len = i + 2;
        string t = s.substr(i, 2);
        m[t]++;
    }

    unordered_map<string, int>::iterator it = m.begin();
    int max = 0;
    string maxstr;
    for (; it != m.end(); it++)
    {
        if (it->second > max)
        {
            max = it->second;
            maxstr = it->first;
        }
    }
    cout << maxstr;
    return 0;
}
