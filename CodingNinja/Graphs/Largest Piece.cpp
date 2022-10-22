/*It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000

Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/

#include <iostream>
#include <vector>
using namespace std;

int help(vector<vector<int>> &cake, int n, int i, int j, bool **visited)
{
    // checking if out of boundary
    if (i < 0 || j >= n || i >= n || j < 0)
        return 0;

    // checking if already visited
    if (visited[i][j])
        return 0;

    // checking if cake is 1 or not
    if (cake[i][j] == 0)
        return 0;

    visited[i][j] = true;
    int ans = 1;

    ans += help(cake, n, i - 1, j, visited);
    ans += help(cake, n, i, j + 1, visited);
    ans += help(cake, n, i + 1, j, visited);
    ans += help(cake, n, i, j - 1, visited);

    return ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && cake[i][j] == 1)
            {
                int smallans = help(cake, n, i, j, visited);
                if (ans < smallans)
                {
                    ans = smallans;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}