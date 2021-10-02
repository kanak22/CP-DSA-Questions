/*Question Link:
https://leetcode.com/problems/find-k-closest-elements/*/
/*In this question we are requested to find the k number of closest integers closer to the given integer x
In this solution we use an method similar to sliding window approach
A number a is closer to x than another number b when it satisfies any one of the underlying conditions
condition 1:|a-x|<|b-x|
condition 2:|a-x|==|b-x| and a<b
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> vec,vec1,vec2;
        int i=0,j=arr.size()-1,count=0,d=0,count2=0,count3=0;
	//here the given vector is sorted so if the first element is negative,
	//we append k elements to our vector and return it
        if(x<=arr[0])
        {
            for(int i=0;i<k;i++)
            {
                vec.push_back(arr[i]);
                
            }
        return vec;
        }
	//else we check for the conditions which could be satisfied
	// and accordingly we keep track of the index when the number we encounter is more closer to the given number x

        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]<=x)
            {d=i;
                break;}
        }
        i=d;
        j=d+1;
	//After keeping track of the indexes we use two pointer approach iterating from both front and back simultaneously
	//and accordingly we append the k elements and return the vector
        while(i>=0 && j<arr.size() && count!=k)
        {
            if(abs(arr[i]-x)<=abs(arr[j]-x))
            {
                vec.push_back(arr[i]);
                i--;
                count++;
            }
            else if(abs(arr[i]-x)>abs(arr[j]-x))
            {
                vec.push_back(arr[j]);
                j++;
                count++;
            }
            
        }
//Here we cover the cases where one pointer reaches its limit ,other pointer doesn't and the k elements
//has not been satisfied so we cover those condition below
        while(i>=0 && count!=k)
        {
            vec.push_back(arr[i]);
            count++;
            i--;
        }
        while(j<arr.size() && count!=k)
        {
            vec.push_back(arr[j]);
            count++;
            j++;
        }
        
        
 //Finally we sort our vector and return it 
            sort(vec.begin(),vec.end());
            return vec;
        }
        
    
};
/*Sample Input and Sample Output
[1,2,3,4,5]
4
[1,2,3,4]

*/
