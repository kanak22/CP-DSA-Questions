Intutive Approach :
		1. Create a list of all rotten oranges with time elapsed as 0
		2. For all rotten oranges , find their neighboring oranges and make all fresh as rotten 
		3. Increment the timestamp of all the neighbors by +1 simultaneously 
		4. If any fresh oranges left, return -1 
		
		def orangesRotting(grid):
		      
				m = len(grid)
				n = len(grid[0])
				rotten = []
				fresh = 0

                #Fill in values in rotten with all rotten oranges with timestamp as 0 for every entry
				for i in range(0,m):
					for j in range(0,n):
						if grid[i][j] == 2:
							rotten.append((i,j,0))
						elif grid[i][j] ==1:
							fresh+=1
							
                #Edge case where every entry in grid is either 0 or 2
				if fresh ==0:
					return(0)
                
				#Function to return all the neighbors of the current cell
				def neighbors(x,y):
				    #Four directions as stated in question
					dir_x= [-1,1,0,0] 
					dir_y = [0,0,-1,1]

					for i in range(0,4):
						new_x = x+dir_x[i]
						new_y = y+dir_y[i]

						if not (0 <= new_x < m and 0 <= new_y < n): 
							continue

						yield((new_x,new_y))

				seen = set() # To keep track of which cells have been seen as of now 
				
				#Start rotting via BFS
				
				while rotten :
					elem = rotten.pop(0)
					row = elem[0]
					col = elem[1]
					time = elem[2]

					for neighbor in neighbors(row,col):  # Find all the neighbors of current cell
						r = neighbor[0]
						c = neighbor[1]
						if neighbor in seen:   #If already rotten, skip
							continue
						seen.add((r,c))
						if grid[r][c]==1:   #If neighbor is 1 i.e. fresh , then make it rotten i.e.=2
							grid[r][c]=2
							rotten.append((r,c,time+1))  #Increment time simultaneously for all the neighbors of current cell
                 
				#If there is still any fresh oranges left, return -1
				for i in range(0,m):        
					for j in range(0,n):
						if grid[i][j] == 1:
							return(-1)
							
                #return final time elapsed 
				return(time)
				
