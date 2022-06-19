// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

/*Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter
in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.

Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.

Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.

Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        string ans = "";
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        for (int i = 26; i >= 0; i--)
        {
            char u = 'A' + i;
            char l = 'a' + i;
            if (m.count(u) != 0 && m.count(l) != 0)
            {
                ans += u;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    string w1;
    cin >> w1;
    Solution obj;
    cout << obj.greatestLetter(w1);
    return 0;
}