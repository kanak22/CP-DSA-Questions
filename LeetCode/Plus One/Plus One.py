def plusOne(digits):
  n = int(''.join([str(num) for num in digits]))
  n += 1
  return list(str(n))

# Example 1
# Input: [1,2,3]
# Output: [1,2,4]
print(plusOne([1,2,3]))

# Example 2
# Input: [4,3,2,1]
# Output: [4,3,2,2]
print(plusOne([4,3,2,1]))

# Example 3
# Input: [0]
# Output: [1]
print(plusOne([0]))

#Example 4
# Input: [9]
# Output: [1,0]
print(plusOne([9]))
