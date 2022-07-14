// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

/*A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).

Constraints:

1 <= s.length <= 10^5
s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    int minDeletions(string s)
    {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s)
        {
            frequency[c - 'a']++;
        }

        sort(frequency.begin(), frequency.end(), greater<int>());

        int deleteCount = 0;
        // Maximum frequency the current character can have
        int maxFreqAllowed = s.size();

        // Iterate over the frequencies in descending order
        for (int i = 0; i < 26 && frequency[i] > 0; i++)
        {
            // Delete characters to make the frequency equal the maximum frequency allowed
            if (frequency[i] > maxFreqAllowed)
            {
                deleteCount += frequency[i] - maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            // Update the maximum allowed frequency
            maxFreqAllowed = max(0, frequency[i] - 1);
        }

        return deleteCount;
    }
};

// Approach #2
class Solution
{
public:
    int minDeletions(const string &s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        sort(begin(freq), end(freq), greater<int>());
        int prev = freq[0];
        int ans = s.size() - prev;
        for (int i = 1; i < 26; ++i)
        {
            if (freq[i] == 0 || prev == 0)
                break;
            prev = min(freq[i], prev - 1);
            ans -= prev;
        }
        return ans;
    }
};

// Approach #3
class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> m;
        int maxfreq = INT_MIN;
        for (auto i : s)
        {
            m[i]++;
            maxfreq = max(m[i], maxfreq);
        }
        vector<int> a(maxfreq + 1, 0);
        for (auto it : m)
        {
            a[it.second]++;
        }
        int ans = 0;
        bool vacant = true;
        for (int i = maxfreq; i > 0; i--)
        {
            if (a[i] > 1)
            {
                int rem = a[i] - 1;
                if (!vacant)
                {
                    ans += (rem * i);
                    continue;
                }
                for (int j = i - 1; j >= 0 && rem != 0; j--)
                {
                    if (j == 0)
                    {
                        vacant = false;
                        ans += (rem * i);
                        break;
                    }
                    if (a[j] == 0)
                    {
                        a[j] = 1;
                        rem--;
                        ans += (i - j);
                    }
                }
            }
        }
        return ans;
    }
};
