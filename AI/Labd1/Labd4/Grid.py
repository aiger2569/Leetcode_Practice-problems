'''for the question we will focus on a traveller that has to go through a grid like structure and the user will provide the grid size 
for example a 3x3 grid or 4x4 grid and the program will create a grid of that size and the user will provide the start and end points and the program will find the shortest path from start to end using bfs or dfs algorithm
the program will also calculate the number of steps taken to reach the end point from the start point and will also display the path taken by the traveller'''

grid=[]
traveller_position=(0,0)
def createGrid(rows,cols):
    global grid
    grid=[[0 for _ in range(cols)] for _ in range(rows)]
def displayGrid():
    global grid,traveller_position
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if (i,j)==traveller_position:
                print("T",end=" ")
            else:
                print(grid[i][j],end=" ")
        print()
def moveTraveller(direction):
    global traveller_position,grid
    x,y=traveller_position
    if direction=="up" and x>0:
        traveller_position=(x-1,y)
    elif direction=="down" and x<len(grid)-1:
        traveller_position=(x+1,y)
    elif direction=="left" and y>0:
        traveller_position=(x,y-1)
    elif direction=="right" and y<len(grid[0])-1:
        traveller_position=(x,y+1)
def findShortestPath(start,end):
    from collections import deque
    global grid
    rows=len(grid)
    cols=len(grid[0])
    visited=set()
    queue=deque([(start,[start])])
    while queue:
        current,path=queue.popleft()
        if current==end:
            return path
        x,y=current
        for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx,ny=x+dx,y+dy
            if 0<=nx<rows and 0<=ny<cols and (nx,ny) not in visited:
                visited.add((nx,ny))
                queue.append(((nx,ny),path+[(nx,ny)]))
    return None
# Example usage:
createGrid(4,4) 
displayGrid()
print("Moving Traveller Down")  
moveTraveller("down")
displayGrid()
moveTraveller("left")
print("Moving Traveller Left")
displayGrid()
print("Moving Traveller Right")  
moveTraveller("right")
displayGrid()