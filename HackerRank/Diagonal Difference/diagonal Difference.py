#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    # Write your code here
    sumLeft=0
    sumRight = 0
    length = len(arr)
    
    # Finding the sum of left diagonal
    for i in range(length):
        for j in range(length):
            if i==j:
                sumLeft = sumLeft + arr[i][j]
    
    # Finding the sum of right diagonal
    for i in range(length):
        for j in range(length):
            if (i + j) == (length - 1):
                sumRight = sumRight + arr[i][j]
                
    return abs(sumLeft-sumRight)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
