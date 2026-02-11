from collections import deque
import time

def dfs(jug1cap, jug2cap, target, jug1=0, jug2=0, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []

    # If already visited, skip
    if (jug1, jug2) in visited:
        return None

    visited.add((jug1, jug2))
    path.append((jug1, jug2))

    # Goal state (0, target)
    if jug1 == 0 and jug2 == target:
        return path

    # 1. Fill jug1
    result = dfs(jug1cap, jug2cap, target, jug1cap, jug2, visited.copy(), path.copy())
    if result:
        return result

    # 2. Fill jug2
    result = dfs(jug1cap, jug2cap, target, jug1, jug2cap, visited.copy(), path.copy())
    if result:
        return result

    # 3. Empty jug1
    result = dfs(jug1cap, jug2cap, target, 0, jug2, visited.copy(), path.copy())
    if result:
        return result

    # 4. Empty jug2
    result = dfs(jug1cap, jug2cap, target, jug1, 0, visited.copy(), path.copy())
    if result:
        return result

    # 5. Pour jug1 → jug2
    pour = min(jug1, jug2cap - jug2)
    result = dfs(jug1cap, jug2cap, target,
                 jug1 - pour, jug2 + pour,
                 visited.copy(), path.copy())
    if result:
        return result

    # 6. Pour jug2 → jug1
    pour = min(jug2, jug1cap - jug1)
    result = dfs(jug1cap, jug2cap, target,
                 jug1 + pour, jug2 - pour,
                 visited.copy(), path.copy())
    if result:
        return result

    return None


# ---------- Run DFS ----------
start_time = time.time()
solution = dfs(3, 5, 4)
end_time = time.time()

print("DFS Solution Path:")
def display_tree(path):
    for i, (jug1, jug2) in enumerate(path):
        print(f"Step {i}: Jug1 = {jug1}, Jug2 = {jug2}")

display_tree(solution)

print("Time taken for DFS: {:.6f} seconds".format(end_time - start_time))