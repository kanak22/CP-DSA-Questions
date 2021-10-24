def kthSmallest(matrix, k):
  row = k // len(matrix) - 1 
  col = k % len(matrix)
  return matrix[row][col]

# Example 1
# Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
# Output: 13
print(kthSmallest([[1,5,9],[10,11,13],[12,13,15]], 8))

# Example 2
# Input: matrix = [[-5]], k = 1
# Output: -5
print(kthSmallest([[-5]], 1))