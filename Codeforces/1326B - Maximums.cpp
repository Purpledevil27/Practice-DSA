#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> a;
    priority_queue<int> pq;
    a.push_back(b[0]);
    pq.push(b[0]);
    for (int i = 1; i < n; i++)
    {
        int m = pq.top();
        int temp = b[i] + m;
        a.push_back(temp);
        pq.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
