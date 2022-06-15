// https://leetcode.com/problems/longest-string-chain/

/*You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of
the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a
predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> dp;
    static bool mycmp(string const &s1, string const &s2)
    {
        return s1.size() > s2.size();
    }

    int solve(vector<string> &words, string &word, int &ans)
    {
        if (dp.count(word) != 0)
        {
            return dp[word];
        }
        if (word.length() == 1)
        {
            return 1;
        }
        int count = 1;
        for (int i = 0; i < word.length(); i++)
        {
            string test = word;
            test.erase(i, 1);
            if (find(words.begin(), words.end(), test) != words.end())
            {
                count = 1 + solve(words, test, ans);
            }
            ans = max(ans, count);
        }
        dp[word] = count;
        return count;
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), mycmp);
        int n = words.size(), ans = 1;
        int minlen = words[n - 1].length();
        for (int i = 0; i < n - 1; i++)
        {
            if (ans >= words[i].length() - minlen + 1)
            {
                break;
            }
            int count = solve(words, words[i], ans);
        }
        return ans;
    }
};