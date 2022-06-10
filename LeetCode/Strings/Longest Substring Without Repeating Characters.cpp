// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int n = s.length();
        unordered_map<char, int> m;
        int count = 0, start = 0, end = 0;

        for (int i = 0; i < n; i++)
        {
            m[s[end]]++;
            while (m[s[end]] != 1)
            {
                m[s[start]]--;
                start++;
            }
            count = max(count, end - start + 1);
            end++;
        }
        return count;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.lengthOfLongestSubstring(s);
    return 0;
}