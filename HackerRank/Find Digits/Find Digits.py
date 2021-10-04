t=int(input())
for tc in range(t):
    n=input()
    z=list(map(int,list(n)))    # Making a list where it's elements are the digits of that number
    count=0
    for i in z:
        if i>0 and int(n)%i==0:     # We will exclude the digit '0' as it can't be a divisor
            count+=1    # add 1 to our count if a digit is a divisor
    print(count)