
// Question :
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



// Code :
import java.util.Scanner;

public class selling_stocks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length of array");
        int length = sc.nextInt();
        int[] array = new int[length];
        System.out.println("Enter array element");
        for(int i = 0; i < length; i++) {
            array[i] = sc.nextInt();
        }
        int max_profit = maxProfit(array);
        System.out.println(max_profit);
    }

    public static int maxProfit(int[] prices) {
        int left_min=Integer.MAX_VALUE; // Declare a left_min variable which have track of the left minimum values in the array we are traversing
        int profit=0;  // Since negetive profit is not a profit, so we initialize profit variable with 0
        for(int i=0;i<prices.length;i++){
            if(prices[i]<left_min){      // If we find an element which is less than the left_min element then we update it.
                left_min=prices[i];
            }
            int p=prices[i]-left_min;
            if(profit<=p){          // If in case we found the profit which is greater than the prev profit then we just update it.
                profit=p;
            }
        }
        return profit;
    }
}
