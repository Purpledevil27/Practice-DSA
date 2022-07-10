// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/

/*You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure time of the ith bus. You are
also given a 0-indexed integer array passengers of length m, where passengers[j] represents the arrival time of the jth passenger.
All bus departure times are unique. All passenger arrival times are unique.

You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.

The passengers will get on the next available bus. You can get on a bus that will depart at x minutes if you arrive at y minutes
where y <= x, and the bus is not full. Passengers with the earliest arrival times get on the bus first.

Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same time as another passenger.

Note: The arrays buses and passengers are not necessarily sorted.

Example 1:

Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
Output: 16
Explanation:
The 1st bus departs with the 1st passenger.
The 2nd bus departs with you and the 2nd passenger.
Note that you must not arrive at the same time as the passengers, which is why you must arrive before the 2nd passenger to catch the bus.

Example 2:

Input: buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
Output: 20
Explanation:
The 1st bus departs with the 4th passenger.
The 2nd bus departs with the 6th and 2nd passengers.
The 3rd bus departs with the 1st passenger and you.

Constraints:

n == buses.length
m == passengers.length
1 <= n, m, capacity <= 10^5
2 <= buses[i], passengers[i] <= 10^9
Each element in buses is unique.
Each element in passengers is unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        int q = 0;
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size();
        int m = passengers.size();
        set<int> st;
        for (auto p : passengers)
        {
            st.insert(p);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // curr bus depature time.
            int currbus = buses[i];
            // number of people in curr bus
            int count = 0;
            int x;
            // CASE1
            while (q < passengers.size() && count < capacity && passengers[q] <= currbus)
            {
                x = passengers[q];
                q++;
                // checking if person timing-1 doesnt exist and update the answer.
                if (st.find(x - 1) == st.end())
                    ans = x - 1;
                count++;
            }
            // CASE2
            if (count < capacity)
            {
                // starting from dept time find a time which does not exist int the set already.
                while (st.find(currbus) != st.end())
                {
                    currbus--;
                }
                ans = max(ans, currbus);
            }
        }
        return ans;
    }
};

int main()
{
    int buses, passengers, capacity;
    cin >> buses >> passengers >> capacity;
    vector<int> bustime;
    for (int i = 0; i < buses; i++)
    {
        int k;
        cin >> k;
        bustime.push_back(k);
    }
    vector<int> passengerarrivaltime;
    for (int i = 0; i < buses; i++)
    {
        int k;
        cin >> k;
        passengerarrivaltime.push_back(k);
    }
    Solution obj;
    cout << obj.latestTimeCatchTheBus(bustime, passengerarrivaltime, capacity);
    return 0;
}