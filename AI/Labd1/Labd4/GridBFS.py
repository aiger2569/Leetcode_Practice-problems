'''same grib program but based on bfs algorithm to find shortest path from start to end point shows us the progression through the grid
using bfs algorithm to find shortest path from start to end point shows us the progression through the grid we can enter the final position we want to reach and the program will show us the path taken to reach there'''
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
def displayPath(path):
    global traveller_position
    for position in path:
        traveller_position=position
        displayGrid()
        print("-----")
def finalPositionExample():
    start=(0,0)
    end=(3,3)
    path=findShortestPath(start,end)
    if path:
        print("Shortest path from",start,"to",end,":",path)
        displayPath(path)
    else:
        print("No path found from",start,"to",end)
        

# Example usage:
createGrid(4,4) 
displayGrid()
finalPositionExample()
print("Moving Traveller Down")  
moveTraveller("down")   