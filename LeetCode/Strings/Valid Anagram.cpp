// https://leetcode.com/problems/valid-anagram/

/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - Using Two Maps
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> ms, mt;
        for (int i = 0; i < s.size(); i++)
        {
            ms[s[i]]++;
            mt[t[i]]++;
        }
        if (ms.size() != mt.size())
            return false;
        for (auto it : ms)
        {
            if (it.second != mt[it.first])
            {
                return false;
            }
        }
        return true;
    }
};

// Approach #2 - Using One Maps
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++)
        {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second)
                return false;
        return true;
    }
};

// Approach #3
// Using ARRAY to simulate the unordered_map and speed up the code since the problem statement says that "the string contains only lowercase alphabets"
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i])
                return false;
        return true;
    }
};