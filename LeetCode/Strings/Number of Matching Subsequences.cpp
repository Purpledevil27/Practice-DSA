// https://leetcode.com/problems/number-of-matching-subsequences/

/*Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

Constraints:
1 <= s.length <= 5 * 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<int>> charIndex(26);
        for (int i = 0; i < s.size(); i++)
            charIndex[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (auto &word : words)
        {
            int x = -1;
            bool found = true;

            for (auto c : word)
            {
                auto it = upper_bound(charIndex[c - 'a'].begin(), charIndex[c - 'a'].end(), x);
                if (it == charIndex[c - 'a'].end())
                {
                    found = false;
                    break;
                }
                else
                    x = *it;
            }
            if (found)
                ans++;
        }
        return ans;
    }
};

// Gives TLE
/*class TrieNode{
    public:
    TrieNode *children[26];
    char data;

    TrieNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string const &word){
        TrieNode *temp = root;
        for(int i=0;i<word.length();i++){
            temp->children[word[i]-'a'] = new TrieNode(word[i]);
            temp = temp->children[word[i]-'a'];
        }
    }

    bool help(string word, TrieNode *root){
        if(word.length()==0){
            return true;
        }
        for(int i=0;i<26 && root;i++){
            if(root->children[word[0]-'a']){
                return help(word.substr(1), root->children[word[0]-'a']);
            }
            else if(root->children[i]){
                return help(word, root->children[i]);
            }
        }
        return false;
    }

    bool isMatching(string word){
        return help(word, root);
    }

};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie t;
        t.insert(s);
        int ans =0;
        for(auto &word:words){
            if(t.isMatching(word)){
                ans++;
            }
        }
        return ans;
    }
};*/