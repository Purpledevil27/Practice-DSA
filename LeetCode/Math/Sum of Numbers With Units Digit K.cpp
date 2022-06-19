// https://leetcode.com/problems/num-of-numbers-with-units-digit-k/

/*Given two integers num and k, consider a set of positive integers with the following properties:

The units digit of each integer is k.
The num of the integers is num.
Return the minimum possible size of such a set, or -1 if no such set exists.

Note:

The set can contain multiple instances of the same integer, and the num of an empty set is considered 0.
The units digit of a number is the rightmost digit of the number.

Example 1:

Input: num = 58, k = 9
Output: 2
Explanation:
One valid set is [9,49], as the num is 58 and each integer has a units digit of 9.
Another valid set is [19,39].
It can be shown that 2 is the minimum possible size of a valid set.

Example 2:

Input: num = 37, k = 2
Output: -1
Explanation: It is not possible to obtain a num of 37 using only integers that have a units digit of 2.

Example 3:

Input: num = 0, k = 7
Output: 0
Explanation: The num of an empty set is considered 0.

Constraints:

0 <= num <= 3000
0 <= k <= 9

*/

#include <bits/stdc++.h>
using namespace std;

// Better Code / same approach as below
class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        if (num == 0)
            return 0;
        for (int i = 1; i <= 10; ++i)
            if ((i * k) % 10 == num % 10 && i * k <= num)
                return i;
        return -1;
    }
};

// First Approach
class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        if (num == 0)
        {
            return 0;
        }
        int lnum = num % 10;
        if (k % 10 == lnum)
        {
            return 1;
        }
        int i;
        for (i = 2; i <= 10; i++)
        {
            if (k * i % 10 == lnum)
            {
                break;
            }
        }

        if ((k * i) % 10 == lnum && k * i <= num)
        {
            return i;
        }
        return -1;
    }
};

int main()
{
    int w1, k;
    cin >> w1 >> k;
    Solution obj;
    cout << obj.minimumNumbers(w1, k);
    return 0;
}