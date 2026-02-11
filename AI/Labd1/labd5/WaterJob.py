from collections import deque, defaultdict
from PIL import Image, ImageDraw
import time

# --------------------------------------------------
# BFS SEARCH (BUILD TREE DATA)
# --------------------------------------------------
def bfs_tree(jug1cap, jug2cap, target):
    visited = set()
    queue = deque([(0, 0)])
    parent = {}
    level = {}

    start = (0, 0)
    parent[start] = None
    level[start] = 0

    while queue:
        jug1, jug2 = queue.popleft()

        if (jug1, jug2) in visited:
            continue
        visited.add((jug1, jug2))

        # Goal state (0, target)
        if jug1 == 0 and jug2 == target:
            return parent, level, (jug1, jug2)

        successors = [
            (jug1cap, jug2),         # Fill jug1
            (jug1, jug2cap),         # Fill jug2
            (0, jug2),               # Empty jug1
            (jug1, 0)                # Empty jug2
        ]

        # Pour jug1 → jug2
        pour = min(jug1, jug2cap - jug2)
        successors.append((jug1 - pour, jug2 + pour))

        # Pour jug2 → jug1
        pour = min(jug2, jug1cap - jug1)
        successors.append((jug1 + pour, jug2 - pour))

        for s in successors:
            if s not in parent:
                parent[s] = (jug1, jug2)
                level[s] = level[(jug1, jug2)] + 1
                queue.append(s)

    return parent, level, None


# --------------------------------------------------
# RECONSTRUCT SOLUTION PATH
# --------------------------------------------------
def reconstruct_path(parent, goal):
    path = []
    while goal is not None:
        path.append(goal)
        goal = parent[goal]
    return path[::-1]


# --------------------------------------------------
# DRAW TREE IMAGE USING PILLOW
# --------------------------------------------------
def draw_tree(parent, level):
    width, height = 1400, 900
    img = Image.new("RGB", (width, height), "white")
    draw = ImageDraw.Draw(img)

    node_radius = 20
    level_gap = 120
    node_gap = 80

    nodes_by_level = defaultdict(list)
    for node, lvl in level.items():
        nodes_by_level[lvl].append(node)

    coordinates = {}
    for lvl, nodes in nodes_by_level.items():
        y = 50 + lvl * level_gap
        start_x = (width - (len(nodes) - 1) * node_gap) // 2
        for i, node in enumerate(nodes):
            x = start_x + i * node_gap
            coordinates[node] = (x, y)

    # Draw edges
    for child, par in parent.items():
        if par is not None:
            x1, y1 = coordinates[par]
            x2, y2 = coordinates[child]
            draw.line((x1, y1, x2, y2), fill="black", width=2)

    # Draw nodes
    for node, (x, y) in coordinates.items():
        draw.ellipse(
            (x - node_radius, y - node_radius,
             x + node_radius, y + node_radius),
            outline="black", width=2
        )
        draw.text((x - 15, y - 8), str(node), fill="black")

    img.save("water_jug_bfs_tree.png")
    print("Tree image generated: water_jug_bfs_tree.png")


# --------------------------------------------------
# MAIN EXECUTION
# --------------------------------------------------
if __name__ == "__main__":
    start_time = time.time()

    parent, level, goal = bfs_tree(3, 5, 4)

    if goal:
        path = reconstruct_path(parent, goal)
        print("BFS Solution Path:")
        for i, state in enumerate(path):
            print(f"Step {i}: {state}")
    else:
        print("No solution found.")

    draw_tree(parent, level)

    end_time = time.time()
    print("Time taken for BFS:", end_time - start_time)
