#get a two d  grind from a file and print it in list form
def gridreader(filename):
    grid = []
    with open(filename, 'r') as file:
        for line in file:
            row = line.strip().split()  # Split line into elements
            grid.append(row)
    return grid

fileName = 'grid.txt'  # Replace with your file path
grid = gridreader(fileName)
for row in grid:
    print(row)
    
#print valid neighbors of a cell in the grid
for i in range(len(grid)):
    for j in range(len(grid[0])):
        neighbors = []
        for di in [-1, 0, 1]:
            for dj in [-1, 0, 1]:
                if di == 0 and dj == 0:
                    continue  # Skip the cell itself
                ni, nj = i + di, j + dj
                if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]):
                    neighbors.append((ni, nj))
        print(f"Neighbors of cell ({i}, {j}): {neighbors}")
        
#number of obstacles
invalid_cells = 0
for row in grid:
    for cell in row :
        if cell=="#":
            invalid_cells+=1
print("Number of obstacles in the grid:",invalid_cells)
