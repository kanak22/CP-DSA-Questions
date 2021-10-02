/*
    It is a simple PnC problem
    Approach: 
        As we have to make unique permutations starting from 1, 
        we will fix first position of our permutation with 1.
        So now we are left with N zeroes and M-1 ones.
        We can arrange them in (N+M-1)!/((N)!*(M-1)!) which is equal to (N+M-1)C(N).
    Explanation:
        As total length of the permutation is (N+M) and we have already fixed 1 so we have to arrange (N+M-1) elements
        So total number of ways to rearrange (N+M-1) elements is (N+M-1)!
        And as we have to make unique permutations, we divide (N+M-1)! by how many times one and zero occurs i.e. by (M-1)! and N! respectively.
    Formula Used: 
        nCr = (n-1)C(r-1) + (n-1)C(r)
        Finding factorial will not work as the constraints are too large.
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

long long int solve(int n, int m) {
    // Finding nCr by using formula nCr = (n-1)C(r-1) + (n-1)C(r)
    long long int ncr[n+1][m+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(j==0 || j==i){
                //as nC0 = 1 and nCn = 1
                ncr[i][j]=1;
            }
            else{
                ncr[i][j]=((ncr[i-1][j-1]%mod)+(ncr[i-1][j]%mod))%mod;
            }
        }
    }
    return ncr[n][m];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<solve(n+m-1,n)<<endl;
    }
    return 0;
}
