#THE ADJANCECNY MATRIX PROGRAM USED FOR CALCULATING THE NO OF MISPLACED TILES
#SO THE APPROACH IS TO CREATE A 2D LIST / ARRAY AND THEN INPUT TO SETS OF DATA ONE BEING THE ORIGINAL MATRIX AND OTHER BEING THE GOAL MATRIX
# WE WILL SIMPLY COMPARE THE TWO MATRICES AND COUNT THE NO OF DIFFERENT ELEMENTS
def calculate_misplaced_tiles(currentState, goal_state):
    misplaced_tiles=0
    for i in range(len(currentState)):
        for j in range(len(currentState[i])):
            if currentState[i][j] != goal_state[i][j] and currentState[i][j] != 0:
                misplaced_tiles += 1
    return misplaced_tiles
# Example usage:
currentState = [
    [1, 2, 3], [4, 0, 5], [7, 8, 6] #zero here is used for shits and giggles[blank space]
]
goal_state=[[1, 2, 3], [4, 5, 6], [7, 8, 0]]
misplaced_tiles = calculate_misplaced_tiles(currentState, goal_state)
print("Number of misplaced tiles:", misplaced_tiles)
#the complexity is way high for this one O(n^2) 
#kuch naya sochte hai o{nlogn} tak lane ka sochte hai
