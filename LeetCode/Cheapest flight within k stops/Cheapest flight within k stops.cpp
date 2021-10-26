/*
Link to the question:
https://leetcode.com/problems/cheapest-flights-within-k-stops/

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       int m=INT_MAX;
        queue<pair<int,int>>q;

        // create an adjacency matrix called a.
        vector<vector<vector<int>>>a(n);

        // create a temp vector called b
        vector<int>b;
        // maintain a visited array called v
        int v[n];
        // initialize the visited array to -1
        memset(v,-1,sizeof(v));
        // push source, cost in the queue
        q.push({src,0});
         // form the adjacency matrix
        for(int i=0;i<flights.size();i++)
        {
            // push the destination as well as the cost in b 
            b.push_back(flights[i][1]);
             b.push_back(flights[i][2]);

             // push b in a[flights[i][0]]
            a[flights[i][0]].push_back(b);

            // clear b
            b.clear();
            
        }
        // mark the source as visited
        v[src]=0;
        int c=0;

        // simple bfs 
        while(!q.empty())
        {
            // Level order traversal for the queue
            int n1=q.size();
            for(int i=0;i<n1;i++)
            {

                pair<int,int>p;
                p=q.front();
                q.pop();
                // if the queue front has the destination then update m to min(m,p.second)
                if(p.first==dst)
                {
                    m=min(m,p.second);
                }
              
                for(int i=0;i<a[p.first].size();i++)
                {
                      // now push all the places you can reach from the current source which are not visited
                    if(v[a[p.first][i][0]]==-1)
                    {
                        q.push({a[p.first][i][0],p.second+a[p.first][i][1]});
                        v[a[p.first][i][0]]=p.second+a[p.first][i][1];
                    }
                    else
                    {
                        // if they are visited then check if the cost is greater than the current cost to visit that node
                        // if it is so then we again visit that node.
                        if(v[a[p.first][i][0]]>p.second+a[p.first][i][1])
                        {
                             q.push({a[p.first][i][0],p.second+a[p.first][i][1]});
                             v[a[p.first][i][0]]=p.second+a[p.first][i][1];
                        }
                    }
                }
            }
            // this variable keeps the track of the number of stops
            c++;
            // if c greater than k then break
            if(c>k+1)
            {
                break;
            }
        }
        // if m is still INT_MAX that means we cannot reach the destination hence return -1
        if(m==INT_MAX)
        {
            return -1;
        }
        // else return m
        return m;
    }
};