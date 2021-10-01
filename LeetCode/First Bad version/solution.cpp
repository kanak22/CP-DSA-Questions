class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int h=n;
        int bad=-1;
        int mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(isBadVersion(mid))
            {
                bad=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return bad;
        
    }
};