#include <bits/stdc++.h> //you can skip this when writting on leetcode

using namespace std; //you can skip this when writting on leetcode

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int i,n=a.size(),maxi=0,height,width;
        stack<int> st;
        for(i=0;i<=n;i++){
            while(st.size() && ((i==n) || (a[st.top()]>=a[i]))){
                height=a[st.top()]; st.pop();
                if(st.size()==0) width=i;
                else width=i-st.top()-1;
                maxi=max(maxi, (height*width));
            }
            st.push(i);
        }
        return maxi;
    }
};