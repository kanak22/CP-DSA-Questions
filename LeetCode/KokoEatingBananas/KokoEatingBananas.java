// question link : https://leetcode.com/problems/koko-eating-bananas/

// The problem can be solved using binary search :
/* 
    The approach is simple:
    Step 1 : We find the minimum no of bananas that Koko can eat which is 1 <- this is our start pointer
    Stpe 2: We find the maximum no of bananas that Koko can eat whict is the max in the piles <- this is our end pointer
    Step 3: We do a binary search and check wether Koko can eat the bananas in the provided time which is the mid pointer = start + (end-start) /2
    Step 4: If she can eat the bananas in the given time find a solution for lesser time and move the end pointer to the mid value -> its a potential ans 
    Step 5: If she can't eat the bananas in the given time increase the speed by moving the start pointer to mid + 1
    Note : Here start pointer is minSpeed
                end pointer is maxSpeed
                mid pointer is speed
    Step 6: The loop breaks when the start and the end pointer become equal is pointing to the optimal answer
*/

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int minSpeed = 1;  // start pointer
        int maxSpeed = Integer.MIN_VALUE; // end pointer
        for(int bananas : piles) maxSpeed = Math.max(maxSpeed,bananas);
        while(minSpeed < maxSpeed){
            int speed = minSpeed + (maxSpeed-minSpeed) / 2; // mid pointer
            if(canEatInTime(piles,speed,h)) maxSpeed = speed; // check if she can eat ? decrease the speed : increase the speed
            else minSpeed = speed + 1;
        }
        return minSpeed;
    }

    // function to check if Koko can eat all the bananas in the provided time

    static boolean canEatInTime(int[] piles, int speed , int time){
        int currTime = 0;
        for(int bananas : piles){
            currTime += bananas / speed; 
            if(bananas % speed !=0) currTime++; // if there are bananas still left in the pile it's gonna cost her an extra hour
        }
        return currTime<=time; // check if she can finish in the given time or not
    }
}