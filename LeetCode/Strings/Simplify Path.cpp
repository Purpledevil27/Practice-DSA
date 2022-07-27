// https://leetcode.com/problems/simplify-path/

/*Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level,
and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods
such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Constraints:
1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> pathStack;
        size_t startSearch = 1;
        while (startSearch < path.size())
        {
            size_t endSearch = path.find('/', startSearch);
            string curDir = path.substr(startSearch, endSearch - startSearch);
            if (curDir == "..")
            {
                if (!pathStack.empty())
                {
                    pathStack.pop_back();
                }
            }
            else if (curDir != "" && curDir != ".")
            {
                pathStack.push_back(curDir);
            }
            if (endSearch == string::npos)
                break;
            startSearch = endSearch + 1;
        }
        string result;
        for (const string &dir : pathStack)
        {
            result += '/' + dir;
        }
        return pathStack.empty() ? "/" : result;
    }
};

// Approach #2
class Solution
{
public:
    string simplifyPath(string path)
    {
        string sp = "";
        stack<char> s;
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                if (s.empty() || s.top() != '/')
                    s.push(path[i]);
            }
            else if (path[i] == '.' && s.top() == '/')
            {
                int count = 0, index = i;
                while (index < path.length() && path[index] == '.')
                {
                    index++;
                    count++;
                }
                if (path[index] == '/' || index == path.length())
                {
                    if (count == 1)
                        continue;
                    else if (count == 2)
                    {
                        if (s.size() != 1)
                            s.pop();
                        while (!s.empty() && s.top() != '/')
                            s.pop();
                        i = index;
                    }
                    else
                    {
                        while (count != 0)
                        {
                            s.push('.');
                            count--;
                        }
                        i = index - 1;
                    }
                }
                else
                {
                    while (count != 0)
                    {
                        s.push('.');
                        count--;
                    }
                    i = index - 1;
                }
            }
            else
            {
                s.push(path[i]);
            }
        }
        if (s.size() != 1 && s.top() == '/')
            s.pop();
        while (!s.empty())
        {
            sp += s.top();
            s.pop();
        }
        reverse(sp.begin(), sp.end());
        return sp;
    }
};
