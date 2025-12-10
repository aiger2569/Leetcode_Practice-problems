#now to calculate the degree of a vertex in a graph
#function oriented method to calculate degree of a vertex in an undirected graph using adjacency matrix
def vertex_degree(adj_matrix, vertex):
    degree=0
    n=len(adj_matrix)
    for j in range(n):
        if adj_matrix[vertex][j]==1:
            degree+=1
    return degree
#example adjacency matrix for a square graph
adj_matrix=[[0,1,1,0],
            [1,0,0,1],
            [1,0,0,1],
            [0,1,1,0]]
vertex=2  #calculating degree for vertex 2
deg=vertex_degree(adj_matrix, vertex)
print(f"Degree of vertex {vertex} is:", deg)
#expected output is 2 as vertex 2 is connected to vertex 0 and vertex 3
