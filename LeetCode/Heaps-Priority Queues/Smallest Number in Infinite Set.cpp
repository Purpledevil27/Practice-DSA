// https://leetcode.com/problems/smallest-number-in-infinite-set/

/*You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.

Constraints:

1 <= num <= 1000
At most 1000 calls will be made in total to popSmallest and addBack.
*/

#include <bits/stdc++.h>
using namespace std;

// Using sets - Approach #1
class SmallestInfiniteSet
{
    int cur;
    set<int> s;

public:
    SmallestInfiniteSet()
    {
        cur = 1;
    }
    int popSmallest()
    {
        if (s.size())
        {
            int res = *s.begin();
            s.erase(res);
            return res;
        }
        else
        {
            cur += 1;
            return cur - 1;
        }
    }

    void addBack(int num)
    {
        if (cur > num)
            s.insert(num);
    }
};

// Using Set - Approach #2
class SmallestInfiniteSet
{
    set<int> s;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i < 1001; i++)
        {
            s.emplace(i);
        }
    }

    int popSmallest()
    {
        int min = *s.begin();
        s.erase(min);
        return min;
    }

    void addBack(int num)
    {
        if (s.find(num) == s.end())
        {
            s.emplace(num);
        }
    }
};

// Using Heap and Hashmap - Approach #3
class SmallestInfiniteSet
{
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> m;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i < 1001; i++)
        {
            pq.push(i);
            m[i] = 1;
        }
    }

    int popSmallest()
    {
        int min = pq.top();
        pq.pop();
        m.erase(min);
        return min;
    }

    void addBack(int num)
    {
        if (m.count(num) == 0)
        {
            pq.push(num);
            m[num] = 1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */