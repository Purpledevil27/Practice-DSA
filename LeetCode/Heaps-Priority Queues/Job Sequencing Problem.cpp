// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

/*Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

Example 1:

Input:
N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Example 2:

Input:
N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything.
Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 10^5
1 <= Deadline <= 100
1 <= Profit <= 500
*/

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
// } Driver Code Ends

// Using Priority Queue
class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i].dead, arr[i].profit});
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < v.size(); i++)
        {
            if (pq.size() >= v[i].first)
            {
                if (pq.top() < v[i].second)
                {
                    pq.pop();
                    pq.push(v[i].second);
                }
            }
            else
                pq.push(v[i].second);
        }
        int sum = 0, s = pq.size();
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return {s, sum};
    }
};

// Greedy/Sorting
class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<bool> vis(n, false);

        sort(arr, arr + n, [](Job const &s, Job const &n)
             { return s.profit > n.profit; });
        int deadline = 0;
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int k = min(n, arr[i].dead - 1); k >= 0; k--)
            {
                if (vis[k] == false)
                {
                    vis[k] = true;
                    deadline++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {deadline, profit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends