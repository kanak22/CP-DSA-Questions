long countTriplets(long arr[], int n,int sum)
{
    /// First we sort the array in increasing order
    Arrays.sort(arr);
    long count = 0; /// initialised counter to 0

    /// Three Pointer Approach
    for(int i=0;i<n;i++){
        /// We fixed our first pointer at ith position
        int s=i+1; /// initialised second pointer at i+1 th position
        int e=n-1; /// initialised third pointer at last position
        while(s<e){
            if((arr[i]+arr[s]+arr[e])>=sum) e--; /// if the sum is greater than the expected sum then we are decreasing our third pointer by 1
            /// as the element at e-1 position will be smaller than the element at e position (as array is sorted) and it will lead us to a smaller sum 
            else{
                // Now if the sum is smaller than the expected sum (k) it means for every triplet (arr[i],arr[s] and remaining elements which are at position greater than s and less than or equal to position e) will have sum less than the ecpected sum
                /// Hence we increase our count by e-s
                count+=e-s;
                s++; // as we have calculated all the pairs for the current s position, so we increment it
            }
        }
    }
    return count;
}