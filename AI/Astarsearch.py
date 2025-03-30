import heapq

def a_star_search(graph, start, goal, heuristic):
    # Priority queue to store (f, g, node, path)
    priority_queue = [(0 + heuristic[start], 0, start, [])]
    visited = set()

    while priority_queue:
        f, g, node, path = heapq.heappop(priority_queue)
        
        if node in visited:
            continue
        
        path = path + [node]
        visited.add(node)

        if node == goal:
            return path

        for neighbor, cost in graph[node]:
            if neighbor not in visited:
                g_new = g + cost
                f_new = g_new + heuristic[neighbor]
                heapq.heappush(priority_queue, (f_new, g_new, neighbor, path))

    return "No path found"

# Example graph represented as an adjacency list
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 3), ('E', 5)],
    'C': [('F', 2)],
    'D': [('F', 1)],
    'E': [('F', 2)],
    'F': []
}

# Example heuristic values for each node
heuristic = {
    'A': 7,
    'B': 6,
    'C': 2,
    'D': 1,
    'E': 3,
    'F': 0
}

graph = {
    'A': [('M',3)],    
    'C': [('M',6),('R',2),('U',3)],
    'E': [('S',1),('U',5)],
    'L': [('N',5)],
    'M': [('L',2),('U',5)],
    'N': [('S',6)],
    'P': [('C',4),('R',4)],
    'R': [('E',5)],
    'U': [('N',5),('S',4)],
    'S': []
}


heuristic = {
    'A': 11,
    'C': 6,
    'E': 3,
    'L': 6,
    'M': 9,
    'N': 6,
    'P': 10,
    'R': 8,
    'U': 4,
    'S': 0
}


# Perform A* Search from 'A' to 'F'
path = a_star_search(graph, 'P', 'S', heuristic)
print(f"Path: {path}")
