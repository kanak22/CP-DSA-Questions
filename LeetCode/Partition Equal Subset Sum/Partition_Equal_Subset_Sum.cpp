#include<bits/stdc++.h>

using namespace std;

// Function to check whether the given vector 'nums' has a subset where the
// sum of all elements in it is 'sum'
// Approach : Bottom-Up Approach
bool solve(vector<int> nums, int sum, int n) {
    int dp[n+1][sum+1];

    // Base Case
    // when sum is zero and the number of elements are >= 0
    for(int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }
    // when there are no elements in the vector
    for(int i = 0; i < sum+1; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            // cur_element is greater than the required sum
            if(nums[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            // cur_element is less than or equal to the required sum
            if(nums[i-1] <= j) {
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

// Wrapper function for the solve()
bool canPartition(vector<int> nums) {
    int n = nums.size();
    int total_sum = 0;
    for(int i = 0; i < n; i++) {
        total_sum += nums[i];
    }

    // If total sum is odd, then it cannot be  partitoned into two subsets with equal sum
    if(total_sum % 2 == 1) {
        return false;
    }

    // sum / 2, because the other half sum would be definetely equal as well
    return solve(nums, total_sum / 2, n);
}

// Driver Code
int main() {

    vector<int> nums {1, 2, 3, 5};

    if(canPartition(nums)) {
        cout << "Partition is possible such that both the subsets have equal sum." << "\n";
    } else {
        cout << "Partition cannot be done!" << "\n";
    }

    return 0;
}