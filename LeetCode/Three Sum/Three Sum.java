// https://leetcode.com/problems/3sum/

import java.util.*;

public class Three_Sum {
    public static void main(String[] args) {
        int[] nums = { -1, 0, 1, 2, -1, -4 };
        System.out.println(threeSum(nums));
    }

    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        // arraylist to store ans
        ArrayList<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            int j = i + 1;
            int k = nums.length - 1;

            // To avoid duplicate number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while (j < k) {
                // To avoid duplicate value for k
                if (k < nums.length - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }

                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    ArrayList<Integer> l = new ArrayList<>();
                    l.add(nums[i]);
                    l.add(nums[j]);
                    l.add(nums[k]);
                    ans.add(l);
                    j++;
                    k--;
                }
            }
        }

        return ans;
    }
}
