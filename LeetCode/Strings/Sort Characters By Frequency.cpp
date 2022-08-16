// https://leetcode.com/problems/sort-characters-by-frequency/

/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Constraints:
1 <= s.length <= 5 * 10^5
s consists of uppercase and lowercase English letters and digits.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    string frequencySort(string s)
    {
        std::unordered_map<int, int> m;

        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        vector<pair<char, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), [](pair<char, int> &s, pair<char, int> &n)
             { return ((s.second) > (n.second)); });
        int index = 0;
        for (auto &it : v)
        {
            int n = it.second;
            while (n--)
            {
                s[index++] = it.first;
            }
        }
        return s;
    }
};

// Approach #2
class Solution
{
public:
    string frequencySort(string s)
    {
        //* create a hasmap with freq and char
        vector<pair<int, char>> hash('z' + 1, {0, 0}); // 'z'+1 is the size
        for (auto c : s)
        {
            hash[c] = {hash[c].first + 1, c};
        }
        sort(hash.begin(), hash.end());
        string ans = "";
        for (auto ele : hash)
        {
            ans = string(ele.first, ele.second) + ans;
            // string(size, char): and also add ans to the end
        }
        return ans;
    }
};