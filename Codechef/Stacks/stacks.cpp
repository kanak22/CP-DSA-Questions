#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<long> stack;
    long temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(stack.size()==0)
            stack.push_back(temp);
        else{
            long length = stack.size(), j=0;
            bool rep = false;
            //current disk can replace any of the available disk
            //inserting on some existing stack
            while(j<length){
                if(temp<stack[j]){
                    stack[j] = temp;
                    rep = true;
                    break;
                }
                j++;
            }
            //if current disk could not able to fit on any stack
            if(!rep){
                //finding the correct position for current disk to be inserted
                long start = 0, end = length-1;
                long pos = length;
                while(start<=end){
                    long mid = start + ((end-start)>>1);
                    if(temp<=stack[mid]){
                        pos = mid;
                        end = mid-1;
                    }
                    else
                        start = mid+1;
                }
                stack.insert(stack.begin()+pos, temp);
            }
        }
    }

    //o/p
    cout<<stack.size()<<' ';
    for(int i=0; i<stack.size(); i++)
        cout<<stack[i]<<' ';
    cout<<'\n';
    
    
}

int main() {
    
    //for fast I/O;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int testCase;
	cin >> testCase;
	
	while(testCase--){
	    solve();
	}
	
	return 0;
}