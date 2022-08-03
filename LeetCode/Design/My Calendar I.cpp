// https://leetcode.com/problems/my-calendar-i/

/*You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.

Constraints:
0 <= start < end <= 10^9
At most 1000 calls will be made to book.
*/

#include <bits/stdc++.h>
using namespace std;

// using sets
class MyCalendar
{
public:
    set<pair<int, int>> s;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = s.lower_bound({start, end});
        bool ans;
        if (it == s.end())
        {
            if (s.size())
            {
                auto it1 = it;
                it1--;
                if (start >= (*it1).second)
                    ans = true;
                else
                    ans = false;
            }
            else
                ans = true;
        }
        else if (it == s.begin())
        {
            if (end <= (*it).first)
                ans = true;
            else
                ans = false;
        }
        else
        {
            auto it1 = it;
            it1--;
            if (end <= (*it).first && start >= (*it1).second)
                ans = true;
            else
                ans = false;
        }
        if (ans)
            s.insert({start, end});
        return ans;
    }
};

// using vector
class MyCalendar
{
    vector<pair<int, int>> v;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        bool push = true;
        for (int i = 0; i < v.size(); i++)
        {
            pair<int, int> p = v[i];
            if (start >= p.first && start < p.second)
            {
                push = false;
                break;
            }
            else if (start < p.first && end > p.first)
            {
                push = false;
                break;
            }
        }
        if (push)
        {
            v.push_back({start, end});
        }
        return push;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */