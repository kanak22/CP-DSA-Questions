for _ in range(int(input())):
        dollars = int(input())
        numFlavors = int(input())
        flavors = [int(i) for i in input().split()]
        index1, index2 = -1, -1
        for i in range(numFlavors):
            for j in range(numFlavors):
                if (i != j) and (flavors[i] + flavors[j] == dollars):   #they must be distinct flavour and their sum must be equal to the budget
                    index1 = i + 1
                    index2 = j + 1
                    break
            if index1 != -1 and index2 != -1:
                break
        print(str(index1) + " " + str(index2))