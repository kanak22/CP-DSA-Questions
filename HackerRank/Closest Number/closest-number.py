"""First calculate the power and the remainder. As from the constraints the index can be negative too.
So we can't apply the inbuilt pow() function for computing the reaminder. Just using the basic operators is sufficient.
Then if the remainder is greater than half of x, compute the value (remainder - x) and subtract that from power.
Else just subtract the remainder from the power. That value is the expected result
"""
T = int(input())
for _ in range(T):
    a, b, x = map(int, input().split())
    y = a ** b 
    z = y % x 
    if z > x // 2:
        print(int(y + x - z))
    else:
        print(int(y - z))