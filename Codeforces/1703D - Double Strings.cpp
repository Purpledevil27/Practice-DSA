// Using Tries - Approach #1
#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    bool search1(TrieNode *root, string word)
    {
        int n = word.length();
        if (n == 0)
        {
            return true;
        }
        for (int i = 1; i < n; i++)
        {
            if (find(root, word.substr(0, i)) && find(root, word.substr(i, n - i)))
            {
                return true;
            }
        }
        return false;
    }

    bool search(string word)
    {
        return search1(root, word);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> w;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            w.push_back(s);
        }
        Trie t;
        for (auto i : w)
        {
            t.insert(i);
        }
        string ans = "";
        for (auto i : w)
        {
            if (t.search(i))
            {
                ans += "1";
            }
            else
            {
                ans += "0";
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// Using Hashmaps - Approach #2
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    string s[n];
    map<string, bool> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        mp[s[i]] = true;
    }
    for (int i = 0; i < n; i++)
    {
        bool ok = false;
        for (int j = 1; j < s[i].length(); j++)
        {
            string pref = s[i].substr(0, j), suff = s[i].substr(j, s[i].length() - j);
            if (mp[pref] && mp[suff])
            {
                ok = true;
            }
        }
        cout << ok;
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        solve();
    }
    // solve();
}