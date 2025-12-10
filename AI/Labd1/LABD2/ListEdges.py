#a similar program to list no of edges but based on adjancency list representation of graph
#function oriented method to count edges in an undirected graph using adjacency list
def countEdges(adjList):
    edges=0
    for vertex in adjList:
        edges+=len(adjList[vertex])
        #TO Avoid the double counting 
        # 
    return edges//2
    #we will use the same square graph as the last 
# Use string labels for vertices so Python treats them as keys/strings
adjList={'A': ['B', 'C'], 'B': ['A', 'D'], 'C': ['A', 'D'], 'D': ['B', 'C']}
#to define the values of the adjacency list we will use the same square graph as the last problem

NUMedges=countEdges(adjList)
print("Number of edges in the graph:",NUMedges)
#our expected otut put is 4 here as well a fantastic job done[my granny call me travy you work to hard ball ball ball]
