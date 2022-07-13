// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#

/*Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.

Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac
god dog
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.

Example 2:

Input:
N = 3
words[] = {no,on,is}
Output:
no on
is
Explanation: There are 2 groups of anagrams "no", "on" make group 1. "is" makes group 2.

Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.

Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.

Constraints:
1<=N<=100
1<=|S|<=10
*/

// Using Tries - Approach #1

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
public:
    bool isTerminal;
    TrieNode **children;

    TrieNode()
    {
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string &word, int index, unordered_map<TrieNode *, vector<int>> &m)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->children[word[i] - 'a'] == NULL)
            {
                temp->children[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->isTerminal = true;
        m[temp].push_back(index);
    }
};

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        Trie t;
        unordered_map<TrieNode *, vector<int>> m;
        for (int i = 0; i < string_list.size(); i++)
        {
            string temp = string_list[i];
            sort(temp.begin(), temp.end());
            t.insert(temp, i, m);
        }

        vector<vector<string>> ans;

        for (auto it : m)
        {
            vector<string> temp;
            for (auto i : it.second)
            {
                temp.push_back(string_list[i]);
            }
            ans.push_back(temp);
        }
        return ans;
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends

// // Using Hashmaps - Approach #2 // //

// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        unordered_map<char, int> mc;
        unordered_map<int, int> m;
        vector<vector<string>> ans;
        for (int i = 0; i < string_list.size(); i++)
        {
            if (m.count(i) != 0)
            {
                continue;
            }
            vector<string> v;
            m[i]++;
            v.push_back(string_list[i]);
            for (int j = 0; j < string_list[i].size(); j++)
            {
                char c = string_list[i][j];
                mc[c]++;
            }
            for (int j = i + 1; j < string_list.size(); j++)
            {
                unordered_map<char, int> tempmc = mc;
                if (string_list[i].size() != string_list[j].size())
                {
                    continue;
                }
                bool ana = true;
                for (int k = 0; k < string_list[j].size(); k++)
                {
                    if (tempmc[string_list[j][k]] == 0)
                    {
                        ana = false;
                        break;
                    }
                    else
                    {
                        tempmc[string_list[j][k]]--;
                    }
                }
                if (ana)
                {
                    m[j]++;
                    v.push_back(string_list[j]);
                }
            }
            mc.clear();
            ans.push_back(v);
        }
        return ans;
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends