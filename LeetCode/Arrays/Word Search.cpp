// https://leetcode.com/problems/word-search/
// https://www.geeksforgeeks.org/stdstringfind_last_not_of-in-cpp/
// https://www.geeksforgeeks.org/stdstringfind_first_not_of-in-c/

/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically
neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<vector<char>> &board, string word, /*vector<vector<bool>>& visited,*/ int i, int j)
    {
        if (!word.length())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[0])
        {
            return false;
        }

        /*if(visited[i][j] || board[i][j]!=word[0])
        {
            return;
        }*/

        // visited[i][j]=true;
        char c = board[i][j];
        board[i][j] = '#';
        string s = word.substr(1);

        bool ans = search(board, s, i + 1, j) || search(board, s, i, j + 1) || search(board, s, i - 1, j) || search(board, s, i, j - 1);

        board[i][j] = c;
        // visited[i][j] =false;
        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        int size = word.length();

        // Prune #1 - size of word is greater than board itself
        if (size > m * n)
        {
            return false;
        }

        unordered_map<char, int> count;

        for (auto row : board)
        {
            for (int c : row)
            {
                count[c]++;
            }
        }

        // Prune #2 - board does not contain all occurrences of the chars in the word.
        for (int i = 0; i < word.length(); i++)
        {
            if (count.find(word[i]) != count.end() && count[word[i]] > 0)
            {
                count[word[i]]--;
            }
            else
            {
                return false;
            }
        }

        // Prune #3: Find the longest prefix/suffix of the same character. If the longest
        // suffix is longer than the longest prefix, swap the strigns (so we are less
        // likely to have a long prefix with a lot of the same character).
        int left = word.find_first_not_of(word[0]);
        int right = size - word.find_last_not_of(word[size - 1]);
        if (left > right)
        {
            reverse(word.begin(), word.end());
        }

        // vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (search(board, word, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n, m;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    string s;
    cin >> s;
    Solution obj;
    cout << obj.exist(board, s);
    return 0;
}