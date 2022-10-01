// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

/*
You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.


Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.


Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool equalFrequency(string word)
    {
        unordered_map<char, int> m;
        for (auto &i : word)
            m[i]++;

        if (m.size() == 1)
            return true;

        unordered_map<char, int> m1;
        for (auto &i : m)
            m1[i.second]++;

        if (m1.size() > 2)
            return false;

        if (m1.size() == 1 && m1.count(1) != 0)
            return true;
        else if (m1.size() == 1)
            return false;

        int f = -1, s = -1;
        for (auto &i : m1)
        {
            if (f == -1)
                f = i.first;
            else
                s = i.first;
        }
        if (abs(f - s) != 1)
            return false;
        else
        {
            m1[max(f, s)]--;
            int same = -1;
            for (auto &i : m1)
            {
                if (i.second != 0 && same == -1)
                    same = i.second;
                else
                {
                    if (i.second != 0 && i.second != same)
                        return false;
                }
            }
        }
        return true;
    }
};