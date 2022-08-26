// https://leetcode.com/problems/rearrange-words-in-a-sentence/

/*Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.

Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.

Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"

Constraints:
text begins with a capital letter and then contains lowercase letters and single space between words.
1 <= text.length <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Store all the words in a vector with indices and sort the with the length of string, in case of ties, sort it using the indices
class Solution
{
public:
    string arrangeWords(string text)
    {
        text[0] = tolower(text[0]);
        vector<pair<string, int>> v;
        int n = text.size();
        int s = 0, index = 0;
        for (int i = 0; i < n; i++)
        {
            if (text[i] == ' ' || i == n - 1)
            {
                int len = {i == n - 1 ? i - s + 1 : i - s};
                string t = text.substr(s, len);
                v.push_back({t, index++});
                s = i + 1;
            }
        }

        sort(v.begin(), v.end(), [](pair<string, int> const &s, pair<string, int> const &n)
             {
                 if(s.first.length()==n.first.length()){
                     return s.second < n.second;
                 }
                 return s.first.length()<n.first.length(); });

        string ans = "";
        for (auto &it : v)
        {
            ans += (it.first + " ");
        }

        ans.erase(n, 1);
        ans[0] = toupper(ans[0]);
        return ans;
    }
};