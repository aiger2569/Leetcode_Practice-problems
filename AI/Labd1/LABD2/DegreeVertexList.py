#now to use list instead of matrix to calculate the degree in this graph

def vertex_degree(adjList, vertex):
    degree=0
    if vertex in adjList:
        degree=len(adjList[vertex])
    return degree
#now a example list
adjList={'A': ['B', 'C'], 'B': ['A', 'D'], 'C': ['A', 'D'], 'D': ['B', 'C']}
vertex='C'  #calculating degree for vertex 'C'
deg=vertex_degree(adjList, vertex)
print(f"Degree of vertex {vertex} is:", deg)
#expected output is 2 as vertex C is connected to vertex A and vertex D