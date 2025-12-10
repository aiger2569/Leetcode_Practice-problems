#now we jump to list approach for the direct representation for the graph
def checkDirectConnection(adjList, v1, v2):
    if v1 in adjList and v2 in adjList[v1]:
        return True
    else:
        return False
#the adjacency list for our graph
adjList = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C']
}
if  checkDirectConnection(adjList, 'A', 'D'):
    print("Vertex A and Vertex C are directly connected.")
else:
    print("Vertex A and Vertex C are not directly connected.")