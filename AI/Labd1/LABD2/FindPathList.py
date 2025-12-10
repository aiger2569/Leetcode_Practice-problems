#the same finding the path sequence but using list representation of graph

def findPathList(adjList, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in adjList:
        return None
    for vertex in adjList[start]:
        if vertex not in path:
            newpath = findPathList(adjList, vertex, end, path)
            if newpath:
                return newpath
    return None
#example adjacency list 
adjList={'A': ['B', 'C'],
         'B': ['A', 'D'],
         'C': ['A', 'D'],
         'D': ['B', 'C']}
start='A'
end='D' 
path=findPathList(adjList, start, end)
if path:    
    print(f"Path from {start} to {end} is: {'→'.join(path)}")
else:
    print(f"No path found from {start} to {end}.")