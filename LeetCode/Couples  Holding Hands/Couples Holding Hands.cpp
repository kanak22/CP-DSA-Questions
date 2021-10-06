/**
Think about each couple as a vertex in the graph. So if there are N couples, there are N vertices. Now if in position 2i and 2i +1 there are person from couple u and couple v sitting there, that means that the permutations are going to involve u and v. So we add an edge to connect u and v. The min number of swaps = N - number of connected components.
**/
class Solution {
public:
    int par[65]; // parent array
    int minSwapsCouples(vector<int>& row) {
        memset(par, -1, sizeof(par));
        int n = row.size()/2;
        for(int i = 0; i < n; i++){
            int x = row[i * 2] / 2;
            int y = row[i * 2 + 1] / 2;
            Union(x, y);
        }
        unordered_set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(find(i));
        return n - s.size();
    }
    
    // Union function in Union Find Algorithm
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b)
            par[a] = b;
    }
    
    // Find function in Union Find Algorithm
    int find(int a){
        if(par[a] < 0) return a;
        return par[a] = find(par[a]);
    }
};