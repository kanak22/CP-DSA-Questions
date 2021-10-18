/*
Question Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node.
You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
*/

struct State
{
    // int is 32-bit, there are at most 12 nodes, so path states can be captured by integer
    // state is defined as the path mask, combined with the last visited node
    int pathMask;
    int finalNodeIdx;
    int pathLength;

    State(int pathMask, int finalNodeIdx, int pathLength)
        : pathMask(pathMask),
          finalNodeIdx(finalNodeIdx),
          pathLength(pathLength)
    {
    }

    // key for state -> path mask and last visited node
    int getKey()
    {
        return 100 * pathMask + finalNodeIdx;
    }
};

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> const &graph)
    {
        // use queue for BFS traversal, which contains all valid paths so far
        // pathStates is a hashtable used for filtering out paths that share the same path state
        int n = graph.size();
        queue<State> paths;
        unordered_set<int> pathStates;
        int completedPath = (1 << n) - 1;

        // initialize queue with the different starting nodes
        for (int nodeIdx = 0; nodeIdx < n; ++nodeIdx)
        {
            int pathMask = 1 << nodeIdx;
            State state(pathMask, nodeIdx, 0);
            paths.push(state);
            pathStates.insert(state.getKey());
        }

        while (!paths.empty())
        {
            State state = paths.front();
            paths.pop();

            // visit all neighbors
            int currNodeIdx = state.finalNodeIdx;
            for (size_t idx = 0; idx < graph[currNodeIdx].size(); ++idx)
            {
                // construct new node state
                int newNodeIdx = graph[currNodeIdx][idx];
                State newState(state.pathMask | 1 << newNodeIdx, newNodeIdx, state.pathLength + 1);

                // once completed path has been found -> return result, as this should be the shortest path because of BFS traversal
                if (newState.pathMask == completedPath)
                    return newState.pathLength;

                // if the new path state already existed before -> throw away current path
                // as previous path for that state is guaranteed to be shorter, because of BFS traversal
                if (pathStates.find(newState.getKey()) != pathStates.end())
                    continue;

                // add updated path to queue, and new path state to library
                paths.push(newState);
                pathStates.insert(newState.getKey());
            }
        }

        return 0;
    }
};
