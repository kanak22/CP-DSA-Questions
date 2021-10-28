/**********************************Best TIme to Buy Sell Stocks Solution***************/
/*********************************DP APPROACH*****************************************/
import java.util.Scanner;
public class Best_Time_to_BuySell_Stocks_III{
        public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array");
        int size = sc.nextInt();
        int[] array = new int[size];
        System.out.println("Enter each array element");
        for(int i = 0; i < size; i++) 
        {
            array[i] = sc.nextInt();
        }
        int max_profit = maxProfit(array);
        System.out.println(max_profit);
    }
    public static int maxProfit(int[] prices) {
        // There are  four variables which represent the profit after executing corresponding transaction
        // TTo be noted : 
        // In the beginning, The  profit is 0. 
        // When a stock is bought ,the profit will be deducted of the price of stock.
        int firstBuy = Integer.MIN_VALUE, firstSell = 0;
        int secondBuy = Integer.MIN_VALUE, secondSell = 0;
    
        //What does the varaibles represent
        // (-firstBuy) is min value beteen [0, curPrice.index], firstBuy itself is a negative value
        
        // (firstSell) is max profit between [0, current.index], before update it is max profit between [0, current.index-1], after update is max(firstSell.before, curPrice + firstBuy(e.g. - minValue[0, curPrice.index]))
        
        // (secondBuy) is max profit between [0,curPrice.index] under seen prices if we hold/buy a stock between[0, curPrice.index] and haven't sell it yet.
        
        // (secondSell) is max profit between [0,curPrice.index] under seen prices if we buy a second stock between [0,curPrice.index];
        
        for (int curPrice : prices) {
            if (firstBuy < -curPrice) firstBuy = -curPrice; // the max profit after you buy first stock
            if (firstSell < firstBuy + curPrice) firstSell = firstBuy + curPrice; // the max profit after you sell it
            if (secondBuy < firstSell - curPrice) secondBuy = firstSell - curPrice; // the max profit after you buy the second stock
            if (secondSell < secondBuy + curPrice) secondSell = secondBuy + curPrice; // the max profit after you sell the second stock
        }
        
        return secondSell; // secondSell will be the max profit after passing the prices
    }
}
