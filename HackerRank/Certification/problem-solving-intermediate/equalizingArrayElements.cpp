int minOperations(vector<int> arr, int threshold, int d) {
    int maxSize = 1000000;
    
    vector<int> v[maxSize];
    for(int i=0;i<arr.size();i++){
        int cnt =0;
        
        v[arr[i]].push_back(0);
        
        while(arr[i]>0){
            arr[i] /= d;
            cnt++;
            v[arr[i]].push_back(cnt);
        }
    }
    
    int ans = INT_MAX;
    
    for(int i=0;i<maxSize;i++){
        if(v[i].size() >= threshold){
            int move = 0;
            sort(v[i].begin(),v[i].end());
            
            for(int j=0;j< threshold;j++){
                move += v[i][j];
            }
            
            ans = min(ans,move);
        }
    }
    return ans;
}
