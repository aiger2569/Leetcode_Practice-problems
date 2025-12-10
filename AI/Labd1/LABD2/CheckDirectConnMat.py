#we ought to check whether or not thy matrix has vertecies are connected directly or not[british ahh laughs]
def checkDirectConnection(adjMatrix,v8,v16):#car referncess lol
    if adjMatrix[v8][v16]==1:#monkey got his vine to travel
        return True
    else:
         return False
#the matrix for our graph
adj_matrix=[[0,1,1,0],
            [1,0,0,1],[1,0,0,1],[0,1,1,0]]

v8=0 #first vertex
v16=3 #third vertex
if checkDirectConnection(adj_matrix,v8,v16):
    print(f"Vertex {v8} and Vertex {v16} are directly connected.")
else:
    print("Vertex v8 and Vertex v16 are not directly connected.")