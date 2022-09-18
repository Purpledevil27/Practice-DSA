// https://leetcode.com/problems/count-days-spent-together/

/*Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive).
Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

Example 1:

Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

Example 2:

Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.

Constraints:

All dates are provided in the format "MM-DD".
Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
The given dates are valid dates of a non-leap year.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string start = max(arriveAlice, arriveBob), end = min(leaveAlice, leaveBob);

        if (start <= end)
        {
            int startmonth = stoi(start.substr(0, 2)), startday = stoi(start.substr(3, 2));
            int endmonth = stoi(end.substr(0, 2)), endday = stoi(end.substr(3, 2));
            if (endmonth == startmonth)
            {
                return endday - startday + 1;
            }
            int ans = month[startmonth] - startday;
            for (int i = startmonth + 1; i < endmonth; i++)
            {
                ans += month[i];
            }
            ans += endday + 1;
            return ans;
        }
        return 0;
    }
};

// Approach #2
class Solution
{
    int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Convert date to respective number in year.
    int td(string s)
    {
        int m = s[1] - '0' + 10 * (s[0] - '0');
        int d = s[4] - '0' + 10 * (s[3] - '0');
        --m;
        while (m > 0)
        {
            d += md[m];
            --m;
        }
        return d;
    }

public:
    int countDaysTogether(string sa1, string sa2, string sb1, string sb2)
    {
        int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
        int ans = 0;
        // Check all 365 days in year
        for (int i = 0; i < 367; ++i)
        {
            if (a1 <= i && i <= a2 && b1 <= i && i <= b2)
            {
                ++ans;
            }
        }
        return ans;
    }
};