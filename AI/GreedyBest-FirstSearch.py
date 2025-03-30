import heapq

def greedy_best_first_search(graph, start, goal, heuristic):
    # Priority queue to store (heuristic value, node, path)
    priority_queue = [(heuristic[start], start, [])]
    visited = set()

    while priority_queue:
        _, node, path = heapq.heappop(priority_queue)
        
        if node in visited:
            continue
        
        path = path + [node]
        visited.add(node)

        if node == goal:
            return path

        for neighbor in graph[node]:
            if neighbor not in visited:
                heapq.heappush(priority_queue, (heuristic[neighbor], neighbor, path))

    return "No path found"

# Example graph represented as an adjacency list
# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [],
#     'E': ['F'],
#     'F': []
# }

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['D','F'],
    'D': ['G'],
    'E': ['F'],
    'F': ['G'],
    'G': []
}




# Example heuristic values for each node
# heuristic = {
#     'A': 3,
#     'B': 2,
#     'C': 1,
#     'D': 6,
#     'E': 4,
#     'F': 0
# }

# heuristic = {
#     'A': 10,
#     'B': 8,
#     'C': 9,
#     'D': 4,
#     'E': 3,
#     'F': 7,
#     'G': 0
# }

graph = {
    'A': ['M'],    
    'C': ['M','R','U'],
    'E': ['S','U'],
    'L': ['N'],
    'M': ['L','U'],
    'N': ['S'],
    'P': ['C','R'],
    'R': ['E'],
    'U': ['N','S'],
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



# Perform Greedy Best-First Search from 'A' to 'F'
path = greedy_best_first_search(graph, 'P', 'S', heuristic)
print(f"Path: {path}")
