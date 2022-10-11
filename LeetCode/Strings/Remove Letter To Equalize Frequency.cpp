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
        unordered_map<char, int> mp;
        map<int, int> mp2;
        for (auto c : word)
            mp[c]++;

        for (auto m : mp)
            mp2[m.second]++;

        if (mp2.size() > 2)
            return false;
        map<int, int>::iterator it1 = mp2.begin();
        map<int, int>::iterator it2 = mp2.begin();
        it2++;

        if (mp2.size() == 1)
        {
            if (mp.size() == 1 || it1->first == 1)
                return true;
            return false;
        }

        if (it1->first == 1 && it1->second == 1)
            return true;
        if (it1->first == it2->first - 1 && it2->second == 1)
            return true;
        return false;
    }
};