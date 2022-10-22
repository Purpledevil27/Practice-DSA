// https://practice.geeksforgeeks.org/problems/burning-tree/1

/*Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

Example 1:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    /
 8    10
Target Node = 10
Output: 5

Your Task:
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 10^4
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void makegraph(Node *root, unordered_map<int, vector<int>> &m)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();
            if (t->left)
            {
                m[t->data].push_back(t->left->data);
                m[t->left->data].push_back(t->data);
                q.push(t->left);
            }
            if (t->right)
            {
                m[t->data].push_back(t->right->data);
                m[t->right->data].push_back(t->data);
                q.push(t->right);
            }
        }
    }

public:
    int minTime(Node *root, int target)
    {
        unordered_map<int, vector<int>> m;
        makegraph(root, m);
        queue<int> q;
        q.push(target);
        unordered_map<int, int> vis;
        int ans = -1;
        while (!q.empty())
        {
            int size = q.size();
            ans++;
            while (size--)
            {
                int front = q.front();
                q.pop();
                vis[front]++;
                for (auto &i : m[front])
                {
                    if (vis[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}

// } Driver Code Ends