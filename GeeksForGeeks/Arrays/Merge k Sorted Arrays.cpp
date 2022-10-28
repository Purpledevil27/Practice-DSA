// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

/*Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6],
[7, 8, 9]]
The merged list will be
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6]  [7, 8, 9, 9 ]]
The merged list will be
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5,
6, 6, 7, 8, 9, 9 ].
Your Task:
You do not need to read input or print anything. Your task is to complete mergeKArrays() function which takes 2 arguments, an arr[K][K] 2D Matrix containing K sorted arrays and an integer K denoting the number of sorted arrays, as input and returns the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python)

Expected Time Complexity: O(K^2*Log(K))
Expected Auxiliary Space: O(K^2)

Constraints:
1 <= K <= 100
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void mergearray(vector<int> &o1, vector<int> &o2, vector<int> &o)
    {

        int index1 = o1.size() - 1, index2 = o2.size() - 1, vindex = o.size() - 1;

        while (index1 >= 0 && index2 >= 0)
        {
            if (o1[index1] > o2[index2])
            {
                o[vindex--] = o1[index1--];
            }
            else
            {
                o[vindex--] = o2[index2--];
            }
        }

        while (index1 >= 0)
        {
            o[vindex--] = o1[index1--];
        }

        while (index2 >= 0)
        {
            o[vindex--] = o2[index2--];
        }
    }

    void merge(vector<vector<int>> &arr, int i, int j, vector<int> &o)
    {
        if (i == j)
        {
            for (int k = 0; k < arr.size(); k++)
            {
                o[k] = arr[i][k];
            }
            return;
        }

        if (abs(i - j) == 1)
        {
            mergearray(arr[i], arr[j], o);
        }

        int n = arr.size();

        int mid = (i + j) / 2;

        vector<int> o1((mid - i + 1) * n), o2((j - (mid + 1) + 1) * n);

        merge(arr, i, mid, o1);
        merge(arr, mid + 1, j, o2);

        mergearray(o1, o2, o);
    }

public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n = arr.size();
        vector<int> output(n * K);
        merge(arr, 0, arr.size() - 1, output);
        return output;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends