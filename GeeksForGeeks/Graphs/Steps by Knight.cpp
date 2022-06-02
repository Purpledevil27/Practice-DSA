
/*Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will
take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}

Output:
3

Explanation:

Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the
initial position of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the chessboard (N) as input
parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target
position.

Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(N^2).

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void min(int knightX, int knightY, int targetX, int targetY, vector<vector<bool>> &visited, int &ans, int n)
    {
        queue<int> pendingX;
        queue<int> pendingY;

        pendingX.push(knightX);
        pendingY.push(knightY);
        pendingX.push(-1);
        pendingY.push(-1);
        visited[knightX][knightY] = true;
        while (!pendingX.empty() && !pendingY.empty())
        {
            int currX = pendingX.front();
            int currY = pendingY.front();

            pendingX.pop();
            pendingY.pop();
            if (currX == -1 && currY == -1)
            {
                pendingX.push(-1);
                pendingY.push(-1);
                ans++;
            }
            else
            {
                if (currX == targetX && currY == targetY)
                {
                    return;
                }
                if ((currX - 2 > 0 && currY + 1 > 0) && (currX - 2 <= n && currY + 1 <= n) && !visited[currX - 2][currY + 1])
                {
                    pendingX.push(currX - 2);
                    pendingY.push(currY + 1);
                    visited[currX - 2][currY + 1] = true;
                }
                if ((currX - 1 > 0 && currY + 2 > 0) && (currX - 1 <= n && currY + 2 <= n) && !visited[currX - 1][currY + 2])
                {
                    pendingX.push(currX - 1);
                    pendingY.push(currY + 2);
                    visited[currX - 1][currY + 2] = true;
                }
                if ((currX + 1 > 0 && currY + 2 > 0) && (currX + 1 <= n && currY + 2 <= n) && !visited[currX + 1][currY + 2])
                {
                    pendingX.push(currX + 1);
                    pendingY.push(currY + 2);
                    visited[currX + 1][currY + 2] = true;
                }
                if ((currX + 2 > 0 && currY + 1 > 0) && (currX + 2 <= n && currY + 1 <= n) && !visited[currX + 2][currY + 1])
                {
                    pendingX.push(currX + 2);
                    pendingY.push(currY + 1);
                    visited[currX + 2][currY + 1] = true;
                }
                if ((currX + 2 > 0 && currY - 1 > 0) && (currX + 2 <= n && currY - 1 <= n) && !visited[currX + 2][currY - 1])
                {
                    pendingX.push(currX + 2);
                    pendingY.push(currY - 1);
                    visited[currX + 2][currY - 1] = true;
                }
                if ((currX + 1 > 0 && currY - 2 > 0) && (currX + 1 <= n && currY - 2 <= n) && !visited[currX + 1][currY - 2])
                {
                    pendingX.push(currX + 1);
                    pendingY.push(currY - 2);
                    visited[currX + 1][currY - 2] = true;
                }
                if ((currX - 1 > 0 && currY - 2 > 0) && (currX - 1 <= n && currY - 2 <= n) && !visited[currX - 1][currY - 2])
                {
                    pendingX.push(currX - 1);
                    pendingY.push(currY - 2);
                    visited[currX - 1][currY - 2] = true;
                }
                if ((currX - 2 > 0 && currY - 1 > 0) && (currX - 2 <= n && currY - 1 <= n) && !visited[currX - 2][currY - 1])
                {
                    pendingX.push(currX - 2);
                    pendingY.push(currY - 1);
                    visited[currX - 2][currY - 1] = true;
                }
            }
        }
    }

    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        int ans = 0;
        min(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], visited, ans, n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends