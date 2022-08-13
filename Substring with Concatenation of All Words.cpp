// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

/*You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]

Constraints:
1 <= s.length <= 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        // Keep the count of every word in vector of string words
        unordered_map<string, int> count;
        for (auto &word : words)
        {
            count[word]++;
        }
        vector<int> ans;

        int n = s.length(), word_len = words[0].length(), total_words = words.size();

        for (int i = 0; i < n - word_len * total_words + 1; i++)
        {
            // Keeping the count of word that is already covered
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < total_words; j++)
            {
                string t = s.substr(j * word_len + i, word_len);
                if (count.find(t) != count.end())
                {
                    seen[t]++;
                    // if seen words is greater than the count of words then break
                    if (seen[t] > count[t])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            // if j is equal to total number of words then it means we covered all the word in vector of string words
            if (j == total_words)
                ans.push_back(i);
        }
        return ans;
    }
};