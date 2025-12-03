#now for the last program we will go throught process of creating an adjacency matrix from a list of edges
#THE ADJANCECNY MATRIX PROGRAM USED FOR CREATING ADJANCECNY MATRIX FROM LIST OF EDGES 
#and the vertices then use the same misplaced tile calculation method from previous program to calculate the no of misplaced tiles
#using user input for edges and vertices

def create_adjacency_matrix(edges, vertices):
    size=len(vertices)
    adjacency_matrix=[[0 for _ in range(size)] for _ in range(size)]
    vertex_index={vertex: index for index, vertex in enumerate(vertices)}
    for edge in edges:
        src,dest=edge
        if src in vertex_index and dest in vertex_index:
            src_index=vertex_index[src]
            dest_index=vertex_index[dest]
            adjacency_matrix[src_index][dest_index]=1
            adjacency_matrix[dest_index][src_index]=1
    return adjacency_matrix
#user input for edges and vertices
edges=[('0','1'),('0','3'),('1','2'),('2','4')]#it is an undirected graph  
vertices=['0','1','2','3','4']
adjacency_matrix=create_adjacency_matrix(edges,vertices)
print("Adjacency Matrix:")
for row in adjacency_matrix:
    print(row)

