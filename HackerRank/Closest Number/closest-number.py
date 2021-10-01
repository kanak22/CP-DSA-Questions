T = int(input())
for _ in range(T):
    a, b, x = map(int, input().split())
    y = a ** b 
    z = y % x 
    if z > x // 2:
        print(int(y + x - z))
    else:
        print(int(y - z))