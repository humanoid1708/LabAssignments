import heapq

n = 3

dirOptions = [(1,0), (-1, 0), (0, 1), (0, -1)]
dirChar = ['D', 'U', 'R', 'L']

class Node :
    def __init__(self, state, g, h, path, blankPos):
        self.state = state
        self.g = g
        self.h = h
        self.path = path
        self.blankPos = blankPos

    def f(self) :
        return self.g + self.h
    
    def __lt__(self, other) :
        return self.f() < other.f()
    
def calcHeur(state, goal) :
    goalPos = {}
    for i in range(n):
        for j in range(n) :
            goalPos[goal[i][j]] = (i, j)
    
    dist = 0
    for i in range(n):
        for j in range(n) :
            val = state[i][j]
            if(val != 0) :
                gi, gj = goalPos[val]
                dist += abs(i-gi) + abs(j-gj) #Manhattan Distance
    return dist

def matToString(state) :
    num = ""
    for i in range(n) :
        for j in range(n) :
            num += str(state[i][j])
    return num

def isValid(x, y) :
    return 0 <= x < n and 0 <= y < n

def display(state) :
    for row in state:
        print(row)
    print()

def aStar(start, goal) :
    h = calcHeur(start, goal)
    blank = None #
    for i in range(n):
        for j in range(n) :
            if(start[i][j] == 0):
                blank = (i,j)
    openList = []
    closedList = set()
    startNode = Node(start, 0, h, "", blank)
    heapq.heappush(openList, startNode) #

    while openList:
        curr = heapq.heappop(openList)
        stateId = matToString(curr.state)

        if stateId in closedList :
            continue #
        closedList.add(stateId) #

        if curr.state == goal :
            print(f"Solution found in {curr.g} moves!")
            print(f"Path : {curr.path}")
            display(curr.state)
            return True
        
        for d in range(4):
            newX = curr.blankPos[0] + dirOptions[d][0]
            newY = curr.blankPos[1] + dirOptions[d][1]

            if isValid(newX, newY):
                newState = [row[:] for row in curr.state]
                newState[curr.blankPos[0]][curr.blankPos[1]], newState[newX][newY] = newState[newX][newY], newState[curr.blankPos[0]][curr.blankPos[1]]

                newId = matToString(newState)

                if newId not in closedList:
                    newG = curr.g + 1
                    newH = calcHeur(newState, goal)
                    newPath = curr.path + dirChar[d]
                    heapq.heappush(openList, Node(newState, newG, newH, newPath, (newX, newY)))
    print("No solution found")
    return False

def inputMatrix():
    mat = []
    print("Enter numbers row by row: ")
    print()
    for _ in range(n):
        row = list(map(int, input().split()))
        mat.append(row)
    return mat

def main():
    print("Initial matrix")
    start = [[1,2,3],
             [4,5,6],
             [7,8,0]]
    display(start)
    print("Goal matrix")
    goal =  [[0,1,2],
             [3,4,5],
             [6,7,8]]
    display(goal)
    aStar(start, goal)

if __name__ == "__main__":
    main()

