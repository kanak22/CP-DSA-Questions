def linearSearch (arr, target):
	for i in range(len(arr)):
		for j in range(len(arr[i])):
			if (arr[i][j] == target):
				return [i, j]
	return [-1, -1]

# Driver code
arr = [[3, 12, 9], [5, 2, 89], [90, 45, 22]]
target = 89
ans = linearSearch(arr, target)
print(f"Element found at index: [{ans[0]} {ans[1]}]")
