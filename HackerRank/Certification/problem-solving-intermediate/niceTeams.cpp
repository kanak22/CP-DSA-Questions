int maxPairs(vector<int> skillLevel, int minDiff) {
    int size = skillLevel.size();
    
    sort(skillLevel.begin(),skillLevel.end());
    
    int l=0;
    int r = size/2 + 1;
    
    while(r-l > 1){
        
        int m = (l+r)/2;
        bool check = true;
        for(int i=0;i<m;i++){
            check &= (skillLevel[size - m + i] - skillLevel[i] >= minDiff);
        }
        if(check){ l = m ;}
        else {r = m;}
        
    }
    
    return l;
}
