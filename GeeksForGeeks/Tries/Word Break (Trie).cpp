// https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1/#

/*Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Example 1:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung",
"mobile","ice","cream", "icecream", "man",
"go", "mango" }, A = "ilike"
Output: 1
Explanation: The string can be segmented as
"i like".

Example 2:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung",
"mobile","ice","cream", "icecream", "man",
"go", "mango" }, A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as
"i like samsung" or "i like sam sung".

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words,
else return 0. You don't need to read any input or print any output, it is done by driver code.

Expected time complexity: O(n*l) wwhere l is the leght of longest string present in dictionary
Expected auxiliary space: O(|A| + k) , where k = sum of length of all strings present in B

Constraints:
1 <= N <= 12
1 <= s <=1000 , where s = length of string A
 The length of each word is less than 15.
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        for (auto c : word)
        {
            if (temp->children[c - 'a'] == NULL)
            {
                temp->children[c - 'a'] = new TrieNode(c);
            }
            temp = temp->children[c - 'a'];
        }
        temp->isTerminal = true;
    }

    bool find(TrieNode *root, string word)
    {
        int n = word.length();
        TrieNode *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (temp->children[word[i] - 'a'])
            {
                temp = temp->children[word[i] - 'a'];
            }
            else
            {
                return false;
            }
        }
        return temp && (temp->isTerminal);
    }

    bool search(TrieNode *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            return true;
        }
        for (int i = 1; i <= n; i++)
        {
            if (find(root, word.substr(0, i)) && search(root, word.substr(i, n - i)))
            {
                return true;
            }
        }
        return false;
    }

    bool search(string word)
    {
        return search(root, word);
    }
};

class Solution
{
public:
    // A : given string to search
    // B : vector of available strings

    int wordBreak(string A, vector<string> &B)
    {
        Trie t;
        for (auto i : B)
        {
            t.insert(i);
        }
        return t.search(A);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends