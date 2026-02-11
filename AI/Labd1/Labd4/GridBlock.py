'''in this we will put 1 in certain blocks of the grid to represent obstacles and the traveller has to find the shortest path avoiding those obstacles from start to end point using bfs or dfs algorithm   and display the path progression through the grid and returns us the number of steps taken to do so and as well as give us the which algo did it use to find the shortest path bfs or dfs'''
grid=[]
traveller_position=(0,0)
#we will use random to place obstacles
import random
def createGrid(rows,cols,obstacle_count):
    global grid
    grid=[[0 for _ in range(cols)] for _ in range(rows)]
    placed_obstacles=0
    while placed_obstacles<obstacle_count:
        r=random.randint(0,rows-1)
        c=random.randint(0,cols-1)
        if grid[r][c]==0 and (r,c)!=(0,0) and (r,c)!=(rows-1,cols-1):
            grid[r][c]=1
            placed_obstacles+=1
            
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
#we will have two shortest path functions one for bfs and one for dfs

def findShortestPathBfs(start,end):
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
            if 0<=nx<rows and 0<=ny<cols and (nx,ny) not in visited and grid[nx][ny]==0:
                visited.add((nx,ny))
                queue.append(((nx,ny),path+[(nx,ny)]))
    return None
def findShortestPathDFS(start,end):
    from collections import deque
    global grid
    rows=len(grid)
    cols=len(grid[0])
    visited=set()
    stack=deque([(start,[start])])
    while stack:
        current,path=stack.pop()
        if current==end:
            return path
        x,y=current
        for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx,ny=x+dx,y+dy
            if 0<=nx<rows and 0<=ny<cols and (nx,ny) not in visited and grid[nx][ny]==0:
                visited.add((nx,ny))
                stack.append(((nx,ny),path+[(nx,ny)]))
    return None
def displayPath(path):
    global traveller_position
    for position in path:
        traveller_position=position
        displayGrid()
        print("-----")
def finalPositionExample():
    start=(0,0)
    end=(3,1)
    #compare the number of steps taken by bfs and dfs
    path1=findShortestPathDFS(start,end)
    path2=findShortestPathBfs(start,end)
    if path1:
        print("Shortest path from",start,"to",end,"using DFS:",path1)
        displayPath(path1)
    else:
        print("No path found from",start,"to",end,"using DFS")
    if path2:
        print("Shortest path from",start,"to",end,"using BFS:",path2)
        displayPath(path2)
    else:
        print("No path found from",start,"to",end,"using BFS")
        
# Example usage:
createGrid(4,4,4)
print("Initial Grid:")
displayGrid()
finalPositionExample()
print("Final Grid:")
displayGrid()
            

