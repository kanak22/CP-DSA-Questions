''' Given an array of integers. All numbers occur twice except one number which occurs once, find the number
    array = [1,2,3,1,2]
    Required no = 2*(sum_of_array_without_duplicates) - (sum_of_array)
            = 2*(1 + 2 + 3) - (1 + 2 + 3 + 1 + 2) 
            = 2*6 - 9 
            = 12 - 9
            = 3 (required answer)
'''
numbers=list(map(int,input().split()))
sum_without_duplicates=sum(set(numbers))
total_sum=sum(numbers)
print(2*sum_without_duplicates-total_sum)
