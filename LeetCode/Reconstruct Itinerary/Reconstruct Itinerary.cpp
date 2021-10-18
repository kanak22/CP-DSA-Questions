class Solution {
public:
    // Just Eulerian path. Greedy DFS, building the route backwards when retreating.
    unordered_map<string, multiset<string>> connections;
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket : tickets){
            connections[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(string dep){
        while(!connections[dep].empty()){
            string next = *connections[dep].begin();
            connections[dep].erase(connections[dep].begin());
            dfs(next);
        }
        res.push_back(dep);
    }
};