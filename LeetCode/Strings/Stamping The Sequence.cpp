// https://leetcode.com/problems/stamping-the-sequence/

/*You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.

Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.

Example 2:

Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".

Constraints:
1 <= stamp.length <= target.length <= 1000
stamp and target consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> res;
        auto total_stamp = 0, turn_stamp = -1;
        while (turn_stamp)
        {                   // will run until and unless there is some replacement in the target.
            turn_stamp = 0; // initalize to zero to ensure there is some changes in the iteration or it will go // to  infinite loop
            for (int sz = stamp.size(); sz > 0; --sz)
            { // sz ensure how much lenght of stamp we go for and rest will // replaced with '?'.
                for (auto i = 0; i <= stamp.size() - sz; i++)
                { // for iterating over all the position of the stamp.
                    auto new_stamp = string(i, '?') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '?');
                    // cout << string(i, '?') << " . " <<stamp.substr(i, sz) << " . " << string(stamp.size() - sz - i, '?') << endl;
                    // new_stamp is creating new stamp with some portion with '?' and some portion actual target
                    // characters.
                    auto pos = target.find(new_stamp); // find the specific sequence in whole string.
                    while (pos != string::npos)
                    {                       // while loop ensure whole matching subsequence convert to '?'.
                        res.push_back(pos); // storing the initial position as need to return;

                        turn_stamp += sz;
                        fill(begin(target) + pos, begin(target) + pos + stamp.size(), '?'); // converting
                        // character to '?' of target.
                        pos = target.find(new_stamp); // finding next substring in target.
                    }
                }
            }
            total_stamp += turn_stamp; // storing count which ensure that how many characters are replaced.
        }
        reverse(begin(res), end(res));
        return total_stamp == target.size() ? res : vector<int>(); // checking if the all the characters are
        // convered to '?'
    }
};