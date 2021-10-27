/*
Smallest Missing Genetic Value in Each Subtree

There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. You are given a 0-indexed integer array parents, where parents[i] is the parent for node i. Since node 0 is the root, parents[0] == -1.

There are 105 genetic values, each represented by an integer in the inclusive range [1, 105]. You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.

Return an array ans of length n where ans[i] is the smallest genetic value that is missing from the subtree rooted at node i.

The subtree rooted at a node x contains node x and all of its descendant nodes.

Example 1:
Input: parents = [-1,0,0,2], nums = [1,2,3,4]
Output: [5,1,1,1]
Explanation: The answer for each subtree is calculated as follows:
- 0: The subtree contains nodes [0,1,2,3] with values [1,2,3,4]. 5 is the smallest missing value.
- 1: The subtree contains only node 1 with value 2. 1 is the smallest missing value.
- 2: The subtree contains nodes [2,3] with values [3,4]. 1 is the smallest missing value.
- 3: The subtree contains only node 3 with value 4. 1 is the smallest missing value.

Question Link: https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/
*/

class Solution
{
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parent, vector<int> &a)
    {
        int n = a.size();
        vector<int> ans(n, 1);
        vector<vector<int>> graph(n);
        vector<int> valToPosMap(100002, -1);
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != -1)
            {
                graph[parent[i]].push_back(i);
            }
            valToPosMap[a[i]] = i;
        }

        // valToLabelMap -> given a value of the node it gives the label in the preorder labelled node
        // lastChildLabelMap -> given the value of the node it gives the label of the last child node sub rooted under node with value
        vector<int> valToLabelMap(100002, -1), lastChildLabelMap(100002, -1);
        int label = 0;

        // preprocessing step
        preorderLabel(valToLabelMap, a, graph, 0, label, lastChildLabelMap);

        if (valToLabelMap[1] == -1)
            return ans;

        int child = valToPosMap[1];
        int num = 2;
        while (child != -1)
        {
            // obtain label range
            int value = a[child];
            int left = valToLabelMap[value];
            int right = lastChildLabelMap[value];
            int labelOfNum = valToLabelMap[num];

            // check whether number is present in the subtree or not
            if (left <= labelOfNum && labelOfNum <= right)
                // search for next smaller number
                num++;
            else
            {
                ans[child] = num;
                child = parent[child];
            }
        }
        return ans;
    }

    // performs preorder traversal and assigns labels to the nodes starting from node 0
    void preorderLabel(vector<int> &valToLabelMap, vector<int> &a, vector<vector<int>> &graph, int u, int &label, vector<int> &lastChildLabelMap)
    {
        int value = a[u];
        valToLabelMap[value] = label++;
        int labelHere = label - 1;
        for (auto &v : graph[u])
        {
            preorderLabel(valToLabelMap, a, graph, v, label, lastChildLabelMap);
        }
        lastChildLabelMap[value] = label - 1;
    }
};