class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // The idea to solve this problem is to just iterating the given vector from last and adding carry to the ith element.
        // As asked in the question, we have to increment the given number by 1. Thus, initially the Carry is 1.
        
        /*
           Some examples - 
                         9 9 9 9
                               1
                        __________
                       1 0 0 0 0
                       
                       
                       9 9 8 
                           1
                      ________
                       9 9 9
        */
        
        int c = 1;
        
        // Now iterating through the number vector from Right and adding carry. (As we used to do in elementary classes)
        for(int i = digits.size()-1;i>=0;i--)
        {
            // The ith element i.e., the ith digit is stored here in d.
            int d = digits[i];
            
            // Now, updating the ith digit value by adding carry to it and taking modulo by 10.
            
            digits[i] = (d + c) % 10;
            
            // We also need to update carry value if there is some.
            
            c = (d+c)/10;
        }
        // If the carry is non zero then we have to increase the size of the given vector and have to put carry in the beginning.
        if(c != 0)
        {
            digits.emplace(digits.begin(),c);
        }
        
        // Returning the Plus-oned vector.
        
        return digits;
    }
};
