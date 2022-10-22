// https://leetcode.com/problems/top-k-frequent-words/

/*Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

#include <bits/stdc++.h>
using namespace std;

// TC - O(nlogk)
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> m;
        for (auto &s : words)
        {
            m[s]++;
        }

        auto comp = [](pair<int, string> const &s, pair<int, string> const &n)
        {
            if (s.first == n.first)
            {
                return s.second < n.second;
            }
            return s.first > n.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (auto &i : m)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<string> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// TC - O(nlogn)
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> m;
        for (auto &s : words)
        {
            m[s]++;
        }
        vector<pair<int, string>> v;
        for (auto &it : m)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), [](pair<int, string> const &s, pair<int, string> const &n)
             {
                 if(s.first==n.first){
                     return s.second<n.second;
                 }
                 return s.first>n.first; });
        vector<string> ans;
        int kk = 0;
        for (auto &i : v)
        {
            if (kk == k)
                break;
            ans.push_back(i.second);
            kk++;
        }
        return ans;
    }
};