// https://leetcode.com/problems/word-subsets/

/*You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

Constraints:
1 <= words1.length, words2.length <= 10^4
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // function to calculate the frequency of character in a word
    vector<int> find_frequency(string &word)
    {
        vector<int> count(26);
        for (auto &c : word)
        {
            count[c - 'a']++;
        }
        return count;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> freq(26), helper(26);
        for (auto word : words2)
        {
            // finding frequency of every word in words2
            helper = find_frequency(word);
            for (int i = 0; i < 26; i++)
            {
                // freq[i] is the minimum characters required for a word to be universal in words1
                freq[i] = max(freq[i], helper[i]);
            }
        }
        vector<string> ans;
        for (auto word : words1)
        {
            helper = find_frequency(word);
            int i = 0;
            for (i = 0; i < 26; i++)
            {
                // checking if the required number of character are available in word. If not, then we break from the loop.
                if (helper[i] < freq[i])
                {
                    break;
                }
            }
            // adding the word in the answer since it satisfies the criteria.
            if (i == 26)
                ans.push_back(word);
        }
        return ans;
    }
};