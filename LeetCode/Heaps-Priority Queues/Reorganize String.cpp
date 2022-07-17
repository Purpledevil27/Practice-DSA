// https://leetcode.com/problems/reorganize-string/

/*Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"

Example 2:

Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        // sort(s.begin(), s.end());
        int n = s.length();
        vector<char> a(n, '*');
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        for (auto it : m)
        {
            pq.push({it.second, it.first});
        }
        int index = 0;
        while (!pq.empty())
        {
            pair<int, char> p = pq.top();
            pq.pop();
            while (p.first)
            {
                if (index >= n)
                {
                    index = find(a.begin(), a.end(), '*') - a.begin();
                }
                a[index] = p.second;
                if (index > 0 && a[index] == a[index - 1])
                    return "";
                index += 2;
                p.first--;
            }
        }
        s.clear();
        for (auto i : a)
        {
            s += i;
        }
        return s;
    }
};