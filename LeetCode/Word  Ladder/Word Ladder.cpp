/*
    Link of the question:
    https://leetcode.com/problems/word-ladder/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/
class Solution {
public:
   
    int ladderLength(string b, string e, vector<string>& wordList) {
        // maintain an unordered map
        unordered_map<string,int>m;

        int n=wordList.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            // add the words in the unordered map
            m[wordList[i]]=1;
        }
        // if the endword is not present in the wordList then we cannot reach hence return 0
        if(m.find(e)==m.end())
        {
            return 0;
        }
        // we are doing bfs and hence maintain a queue.
        queue<string>q;
        //push the starting word in the queue
        q.push(b);
        // continue until the queue is not empty
        while(!q.empty())
        {
            int o=q.size();
            // level order in queue
            for(int j=0;j<o;j++)
            {

                string c=q.front();
                vector<string>d;
                q.pop();
                // if the front in the queue is the end word then return ans 
                if(c==e)
                {
                    return ans+1;
                }
                // iterating the unordered map
                for(auto i:m)
                {
                    // store the map key in variable p
                    string p=i.first;
                    int t=0,r=-1;
                    // now compare p and the string in the front of the queue
                    for(int h=0;h<p.size();h++)
                    {
                        if(t>=2)
                        {
                            r=0;
                            break;
                        }
                        if(c[h]!=p[h])
                        {
                            t++;
                        }
                    }
                    // if they only differ in one letter then push that word in the queue
                    if(r==-1 && t==1)
                    {
                        q.push(p);
                        d.push_back(p);
                    }
                }
                for(int i=0;i<d.size();i++)
                {
                   // cout<<d[i]<<" "; 
                    m.erase(d[i]);
                }
               // cout<<endl;
            }
            //increment ans
            ans++;
        }
        return 0;
    }
};