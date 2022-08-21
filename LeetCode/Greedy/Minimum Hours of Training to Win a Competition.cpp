// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/

/*You are entering a competition, and are given two positive integers initialEnergy and initialExperience denoting your initial energy and initial experience respectively.

You are also given two 0-indexed integer arrays energy and experience, both of length n.

You will face n opponents in order. The energy and experience of the ith opponent is denoted by energy[i] and experience[i] respectively. When you face an opponent, you need to have both strictly greater experience and energy to defeat them and move to the next opponent if available.

Defeating the ith opponent increases your experience by experience[i], but decreases your energy by energy[i].

Before starting the competition, you can train for some number of hours. After each hour of training, you can either choose to increase your initial experience by one, or increase your initial energy by one.

Return the minimum number of training hours required to defeat all n opponents.

Example 1:

Input: initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
Output: 8
Explanation: You can increase your energy to 11 after 6 hours of training, and your experience to 5 after 2 hours of training.
You face the opponents in the following order:
- You have more energy and experience than the 0th opponent so you win.
  Your energy becomes 11 - 1 = 10, and your experience becomes 5 + 2 = 7.
- You have more energy and experience than the 1st opponent so you win.
  Your energy becomes 10 - 4 = 6, and your experience becomes 7 + 6 = 13.
- You have more energy and experience than the 2nd opponent so you win.
  Your energy becomes 6 - 3 = 3, and your experience becomes 13 + 3 = 16.
- You have more energy and experience than the 3rd opponent so you win.
  Your energy becomes 3 - 2 = 1, and your experience becomes 16 + 1 = 17.
You did a total of 6 + 2 = 8 hours of training before the competition, so we return 8.
It can be proven that no smaller answer exists.

Example 2:

Input: initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
Output: 0
Explanation: You do not need any additional energy or experience to win the competition, so we return 0.

Constraints:
n == energy.length == experience.length
1 <= n <= 100
1 <= initialEnergy, initialExperience, energy[i], experience[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int ans = 0;
        // First handling the energy hours
        // Since Energy is decreasing after every fight. We need our energy to be strictly greater than the sum of total energy.
        int energySum = accumulate(energy.begin(), energy.end(), 0);
        // If the initial energy is greater than energy sum we add 0 and if both are equal then simply add 1 since we can only win if our energy is strictly greater.
        ans += (energySum - initialEnergy >= 0) ? (energySum - initialEnergy + 1) : 0;

        // Now coming to the hours of training required for experience.
        // Since Experience is only increasing after every fight. No of training hours needed is the (max of the diff of opponent experience and current experience) to win over all the opponents
        int t = INT_MIN, currExperience = initialExperience;
        for (int i = 0; i < experience.size(); i++)
        {
            // if current experience is less than or equal to experience it means we need training hours
            if (currExperience <= experience[i])
            {
                // Computing the hours needed. Adding 1 to have stricly greater experience
                t = max(experience[i] - currExperience + 1, t);
            }
            currExperience += experience[i];
        }
        ans += (t != INT_MIN) ? t : 0;
        return ans;
    }
};

// Taking an example for better understanding:
// initalEnergy = 1
// initialExperience = 1
// energy = [1,1,1,1]
// experience = [1,1,1,50]

// first we find energySum which is 4. And is greater than initialEnergy(i.e. 1). So, we add training hours for energy, (4-1+1) = 4 hours.
// Now, for experience, we enter the loop

// case i=0, currExp = 1 and Exp[i] = 1. we need extra training hours to win. So t = (1-1+1) = 1 hour. & currExp updated to 2.
// case i=1, currExp = 2 and Exp[i] = 1. we dont need any extra hours. currExp updated to 3.
// case i=2, currExp = 3 and Exp[i] = 1. we dont need any extra hours. currExp updated to 4.
// case i=3, currExp = 4 and Exp[i] = 50. we need extra training hours to win. So t = max(t, (50-4+1)) = max(1, 47) = 47. So t=47
// and we add 47 to the answer. So now we can that if we do 47 extra training hours for experience. We can defeat opponent 1,2,3 very easily and when we reach to opponent 4. Our experience would become 51 which is just greater than(50) to defeat the last one.