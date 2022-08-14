// https://leetcode.com/problems/word-ladder-ii/

/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:
1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> temp;
    unordered_map<string, int> m;
    string begin;
    void dfs(string s) // Step 2
    {
        temp.push_back(s);
        if (s == begin)
        {
            vector<string> x = temp;
            reverse(x.begin(), x.end());
            ans.push_back(x);
            temp.pop_back();
            return;
        }
        int cur = m[s];
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            for (char cc = 'a'; cc <= 'z'; cc++)
            {
                s[i] = cc;
                if (m.count(s) && m[s] == cur - 1)
                    dfs(s);
            }
            s[i] = c;
        }
        temp.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        begin = beginWord;
        queue<string> q;
        int k = beginWord.size();
        q.push({beginWord});
        m[beginWord] = 0;
        while (!q.empty()) // Step 1
        {
            int n = q.size();
            while (n--)
            {
                string top = q.front();
                q.pop();
                int x = m[top] + 1;
                for (int i = 0; i < k; i++)
                {
                    char temp1 = top[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        top[i] = ch;
                        if (!m.count(top) && dict.count(top))
                            m[top] = x, q.push(top);
                    }
                    top[i] = temp1;
                }
            }
        }
        if (m.count(endWord))
            dfs(endWord);
        return ans;
    }
};