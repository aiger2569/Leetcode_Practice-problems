#this is to find the path matrix of a undirected graph using matrix

#aka use kruskal algo (Floyd-Warshall for reachability)
def path_matrix(adj_matrix):
    n=len(adj_matrix)
    pathMat=[[0 for _ in range(n)] for _ in range(n)]
    next_vertex=[[None for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if adj_matrix[i][j]==1:
                pathMat[i][j]=1
                next_vertex[i][j]=j
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if pathMat[i][k]==1 and pathMat[k][j]==1:
                    pathMat[i][j]=1
                    if next_vertex[i][j] is None:
                        next_vertex[i][j]=next_vertex[i][k]
    
    return pathMat, next_vertex

def reconstruct_path(start, end, next_vertex):
    if next_vertex[start][end] is None:
        return None
    path = [start]
    current = start
    while current != end:
        current = next_vertex[current][end]
        path.append(current)
    return path

#our example matrix lets use alphabetical indexing this time
# Vertices: A=0, B=1, C=2, D=3
adj_matrix=[[0,1,1,0],
            [1,0,0,1],
            [1,0,0,1],
            [0,1,1,0]]
pathMat, next_vertex = path_matrix(adj_matrix)
print("Path Matrix of the graph:")
print("Vertices: A=0, B=1, C=2, D=3\n")

for i in range(len(adj_matrix)):
    for j in range(len(adj_matrix)):
        if i != j:
            path = reconstruct_path(i, j, next_vertex)
            if path:
                path_str = '→'.join([chr(65+v) for v in path])
                print(f"{chr(65+i)} to {chr(65+j)} = {path_str}")
#expected output is a matrix where all vertices are reachable from each other   
