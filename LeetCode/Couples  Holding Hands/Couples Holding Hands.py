def minSwapsCouples(row):
    N = len(row)//2
    # we create an array of arrays to store the couples
    # e.g. [[0,1], [2,3]]
    couples = [[] for _ in range(N)]
    # we may represent the couples by [[0,0], [1,1]] instead of [[0,1],[2,3]]
    for index, element in enumerate(row):
        couples[element//2].append(index//2)
    adj = [[] for _ in range(N)]

    for x, y in couples:
        adj[x].append(y)
        adj[y].append(x)
    cycles = 0

    # we find the number of cycles in adj
    for i in range(N):
        if not adj[i]:
            continue
        cycles += 1
        x, y = i, adj[i].pop()
        while y != i:
            adj[y].remove(x)
            x, y = y, adj[y].pop()

    # the final answer is N minus the number of cycles
    return N - cycles


# Input: row = [0,2,1,3]
# Output: 1
print(minSwapsCouples([0, 2, 1, 3]))

# Input: row = [3,2,0,1]
# Output: 0
print(minSwapsCouples([3, 2, 0, 1]))
