a = [74,-72,94,-53,-59,-3,-66,36,-13,22,73,15,-52,75]

def maxSubArraySum(a):
    current_sequence = 0
    best_sequence = a[0] # Assigning first number of array to best_sequence
    for x in a:
        current_sequence = max(x,current_sequence+x) # Finding the maximum between the current number and sum of current number and sequence
        best_sequence = max(best_sequence,current_sequence)
    return best_sequence     # Returns the sequence whose sum is the highest

# Print the array
print("Largest sum contiguous subarray:",maxSubArraySum(a))
