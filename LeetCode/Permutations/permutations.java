import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        //result array list
        List<List<Integer>> result = new ArrayList<>();
        
        //if nums is null or lenght 0 then return result
        if (nums == null || nums.length == 0) {
            return result;
        }
        
        //calling helper function
        perm(result, nums, 0, nums.length - 1);
        
        //return final result
        return result;
    }

    public void perm(List<List<Integer>> result, int[] nums, int start, int end) {
        if (start >= end) {
            
            //base case
            
            List<Integer> list = new ArrayList<>();
            
            //traversing the numbers array and adding in the list
            for (int num : nums) {
                list.add(num);
            }
            
            //adding the permutation in the final list
            result.add(list);
        } else {
            //swapping positions in order to gain every possible permutation
            for (int i = start; i <= end; i++) {
                //swapping values using helper function
                swap(nums, start, i);
                
                //recursive call
                perm(result, nums, start + 1, end);
                
                //resetting the values for future calls
                swap(nums, start, i);
            }
        }
    }

    //helper function to swap two values
    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
