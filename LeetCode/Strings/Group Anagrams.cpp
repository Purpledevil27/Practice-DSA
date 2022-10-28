// https://leetcode.com/problems/group-anagrams/

/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - using sort function
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;

        for (auto &i : strs)
        {
            string t = i;
            sort(t.begin(), t.end());
            m[t].push_back(i);
        }

        vector<vector<string>> ans;

        for (auto &i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

// Approach #2 - since all char in string is in lowercase, we can use counting sort
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }

private:
    string strSort(string s)
    {
        int counter[26] = {0};
        for (char c : s)
        {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++)
        {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};