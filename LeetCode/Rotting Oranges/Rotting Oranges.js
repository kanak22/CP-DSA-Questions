/**
 * Approach : Use BFS to store rotten oranges 
 * Take out rotten oranges from the queue and rot other possible oranges
 */

// Node class to store nodes of queue
class Node {
    constructor(value) {
        this.value = value
        this.next = null
    }
}

//Queue class to maintain the queue of rotten oranges
class Queue {
    constructor() {
        this.first = null
        this.last = null
        this.size = 0
    }

    //Add to queue
    enqueue(val) {
        let newNode = new Node(val)
        if(!this.first) {
            this.first = newNode
            this.last = newNode
        } else {
            this.last.next = newNode
            this.last = newNode
        }

        return ++this.size
    }

    //Remove from queue
    dequeue() {
        if(!this.first) return null
        let temp = this.first
        if(this.first == this.last) {
            this.last = null
        }
        this.first = this.first.next
        this.size--
        return temp
    }

    //Check if queue is empty
    empty() {
        if(!this.size) {
            return true
        } else {
            return false
        }
    }

    //Get the length of queue
    length() {
        return this.size
    }

    //Get the first item in queue
    front() {
        return this.first
    }

    //Method to print the queue elements
    print() {
        let arr = []
        let current = this.first
        while(current) {
            arr.push(current.value)
            current = current.next
        }
        console.log(arr);
    }
}


function rotOranges(grid) {
    let q = new Queue()
    let r = grid.length
    let c = grid[0].length

    //Enqueue rotten oranges
    for(let i=0;i<r;i++) {
        for(let j=0;j<c;j++) {
            if(grid[i][j] == 2) {
                q.enqueue([i,j])
            }
        }
    }

    let count = 0 // timeframe
    q.enqueue([-1,-1]) // delimeter for each timeframe of rotting
    while(!q.empty()) {
        let front = q.front()
        
        let i = front.value[0]
        let j = front.value[1]

        //delimeter found, and its the last element, processing done,remove it and break
        if(i == -1 && j == -1 && q.length() == 1) {
            q.dequeue()
            break
        } if(i == -1 && j == -1 && q.length() > 1){
            //delimeter reached with other elements in queue, increase timeframe count, dequeue [-1,-1], enqueue to end
            count++
            q.dequeue()
            q.enqueue([-1,-1])
        } else {
            //element found, process it, update it to 2 in grid i.e. rot it, enqueue to grid the newly create rotten value's position
            if((i-1) >=0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2
                q.enqueue([i-1,j])
            }

            if((j-1) >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2
                q.enqueue([i,j-1])
            }

            if((i+1) < r && grid[i+1][j] == 1) {
                grid[i+1][j] = 2
                q.enqueue([i+1,j])
            }

            if((j+1) < c && grid[i][j+1] == 1) {
                grid[i][j+1] = 2
                q.enqueue([i,j+1])
            }

            q.dequeue()
        }
    }

    //check if still a fresh orange is present
    for(let i=0;i<r;i++) {
        for(let j=0;j<c;j++) {
            if(grid[i][j] == 1) {
                return -1
            }
        }
    }

    return count
    
}

console.log(rotOranges([[2,1,1],[0,1,1],[1,0,1]]));


