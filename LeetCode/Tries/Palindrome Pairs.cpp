// https://leetcode.com/problems/palindrome-pairs/

/*Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    int index;
    char data;
    TrieNode *children[26];
    TrieNode(char data)
    {
        this->data = data;
        this->index = -1;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode *root;

    bool is_palindrome(string const &word)
    {
        int i = 0;
        while (i < word.size() / 2)
        {
            if (word[i] != word[(word.size() - 1) - i])
                return false;
            i++;
        }
        return true;
    }

    void get_suffixes(TrieNode const *t, vector<pair<string, int>> &suffixes, string const s = "")
    {
        if (t->index != -1)
        {
            suffixes.emplace_back(s + t->data, t->index);
        }
        for (auto child : t->children)
        {
            if (child)
            {
                get_suffixes(child, suffixes, s + t->data);
            }
        }
    }

public:
    int emptyIndex = -1;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string &word, int &i)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->children[word[i] - 'a'] == NULL)
            {
                temp->children[word[i] - 'a'] = new TrieNode(word[i]);
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->index = i;
    }

    void search(string &word, int &idx, vector<vector<int>> &ans)
    {
        TrieNode *p = root;
        int i = 0;
        // Working for prefixes
        for (; i < word.size(); i++)
        {
            if (p->children[word[i] - 'a'] == NULL)
                break;
            p = p->children[word[i] - 'a'];

            if (p->index != -1)
            {
                if (p->index != idx && is_palindrome(word.substr(i + 1, string::npos)))
                {
                    ans.push_back({idx, p->index});
                }
                if (p->index == idx && emptyIndex != -1)
                {
                    ans.push_back({idx, emptyIndex});
                    ans.push_back({emptyIndex, idx});
                }
            }
        }
        // if there is no prefix found
        if (i < word.size())
        {
            return;
        }
        // Working for suffixes
        for (auto child : p->children)
        {
            if (child == NULL)
            {
                continue;
            }
            vector<pair<string, int>> suffixes;
            get_suffixes(child, suffixes);

            // for (auto [suffix, index] : suffixes)
            for (int i = 0; i < suffixes.size(); i++)
            {
                if (is_palindrome(suffixes[i].first))
                {
                    ans.push_back({idx, suffixes[i].second});
                }
            }
        }
    }
};

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        Trie t;
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].size() == 0)
            {
                t.emptyIndex = i;
            }
            string word = words[i];
            reverse(word.begin(), word.end());
            t.insert(word, i);
        }
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            // reverse(word.begin(), word.end());
            if (word.size() == 0)
            {
                continue;
            }
            t.search(word, i, ans);
        }
        return ans;
    }
};