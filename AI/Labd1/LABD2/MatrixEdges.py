#this to get the no of edges in the matrix of an undirected graph with given adjancency matrix in a function oriented method
#A SQUARE GRAPH WITH FOUR EDGES WILL BE OUR INPUT 
#for input

def count_edges(adj_matrix):
    edges=0
    n=len(adj_matrix)
    for i in range(n):
        for j in range(i,n):
            if adj_matrix[i][j]==1:
                edges+=1
    return edges
#example adjacency matrix for a square graph
adj_matrix=[[0,1,1,0],
            [1,0,0,1],[1,0,0,1],[0,1,1,0]]
numedges=count_edges(adj_matrix)
print("Number of edges in the graph:",numedges)
#excepted output is 4 here....