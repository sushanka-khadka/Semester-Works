import heapq

def uniform_cost_search(graph, start, goal):
    # Priority queue to store (cost, node, path)
    priority_queue = [(0, start, [])]
    visited = set()

    while priority_queue:
        cost, node, path = heapq.heappop(priority_queue)
        
        if node in visited:
            continue
        
        path = path + [node]
        visited.add(node)

        if node == goal:
            return cost, path

        for neighbor, weight in graph[node]:
            if neighbor not in visited:
                heapq.heappush(priority_queue, (cost + weight, neighbor, path))

    return float("inf"), []

# Example graph represented as an adjacency list
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('D', 2), ('E', 5)],
    'C': [('A', 4), ('F', 3)],
    'D': [('B', 2)],
    'E': [('B', 5), ('F', 1)],
    'F': [('C', 3), ('E', 1)]
}

graph = {
    'A': [('B', 5), ('D', 10)],
    'B': [('A', 5), ('C', 4), ('F', 15)],
    'C': [('B', 4), ('E', 8)],
    'D': [('A', 10), ('F', 11)],
    'E': [('C', 8), ('F', 4)],
    'F': [('B', 15), ('D', 11), ('E', 4)]
}

graph = {
    'A': [('B', 13), ('C', 7), ('F', 5)],
    'B': [('A', 13), ('D', 5), ('H', 3)],
    'C': [('A', 7), ('D', 5), ('E', 1), ('G', 5)],
    'D': [('B', 3), ('H', 2), ('C', 5)],
    'E': [('C', 1), ('G', 4)],
    'F': [('A', 5), ('C', 6)],
    'G': [('C', 5), ('E', 4),('F',6)],
    'H': [('B',3),('D', 2)]
}

# Perform UCS from 'A' to 'F'
cost, path = uniform_cost_search(graph, 'A', 'H')
print(f"Cost: {cost}, Path: {path}")
