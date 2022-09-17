// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// https://www.geeksforgeeks.org/count_if-in-c/

/*You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.

Example 2:

Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.

Example 3:

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.

Constraints:
2 <= properties.length <= 10^5
properties[i].length == 2
1 <= attacki, defensei <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 https://github.com/wingkwong/leetcode-the-hard-way
class Solution
{
public:
    // the idea is to
    // 1. rearrange the order of attack and defense
    // 2. count weak characters (those defenses less than the current maximum defense)
    // 3. update the maximum defense
    int numberOfWeakCharacters(vector<vector<int>> &p)
    {
        // the final answer to be returned
        int weakCharacters = 0;
        // record maximum defense. since 1 <= defense_i <= 10 ^ 5
        // we can set the init value to x where x < 1
        int maxDefense = 0;
        // use a hash map to map the attack and defense with greater<int> as a key_compare
        map<int, vector<int>, greater<int>> m;
        for (auto x : p)
            m[x[0]].push_back(x[1]);
        // for each attack
        for (auto x : m)
        {
            // we count the number of weak characters
            // and add it to `weakCharacters`
            weakCharacters += count_if(x.second.begin(), x.second.end(), [&](int curDefense)
                                       { return curDefense < maxDefense; });
            // then update `maxDefense` which is the maximum value in current defenses
            maxDefense = max(maxDefense, *max_element(x.second.begin(), x.second.end()));
        }
        return weakCharacters;
    }
};

// Approach #2
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        int n = properties.size();
        int result = 0;

        int maxAttack = 0;
        for (int i = 0; i < n; i++)
            maxAttack = max(maxAttack, properties[i][0]);

        // maxDefense[i]: max defense for attach value equal to one value
        vector<int> maxDefense(maxAttack + 1, 0);
        for (int i = 0; i < n; i++)
        {
            maxDefense[properties[i][0]] = max(maxDefense[properties[i][0]], properties[i][1]);
        }
        // max defense for attack value >= i
        for (int i = maxAttack - 1; i >= 0; i--)
        {
            // max defense come from items with higher attack!
            maxDefense[i] = max(maxDefense[i], maxDefense[i + 1]);
        }

        for (int i = 0; i < n; i++)
        {
            int attack = properties[i][0];

            // max defense for attack value > current attack ,  if is > current defense, then qualify!
            if (attack != maxAttack && properties[i][1] < maxDefense[attack + 1])
                result++;
        }

        return result;
    }
};

// Approach #3
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), [](vector<int> const &s, vector<int> const &n)
             {if(s[0]!=n[0])
                return s[0]>n[0];
             return s[1]<n[1]; });
        int maxTillNow = INT_MIN;
        int ans = 0;
        for (auto p : properties)
        {
            if (maxTillNow > p[1])
                ans++;
            else
                maxTillNow = p[1];
        }
        return ans;
    }
};
