def depth_limited_search(graph, start, goal, limit):
    def dls(node, goal, limit, path, visited):
        if limit < 0:
            return False
        path.append(node)
        visited.add(node)
        if node == goal:
            return True
        for neighbor in graph[node]:
            if neighbor not in visited:
                if dls(neighbor, goal, limit - 1, path, visited):
                    return True
        path.pop()
        return False

    path = []
    visited = set()
    if dls(start, goal, limit, path, visited):
        return path
    else:
        return "No path found within depth limit"

# Example graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

graph ={
    'A': ['B','D'],
    'B': ['C','F'],
    'C': ['E','G','H'],
    'G': ['E','H'],
    'E': ['B','F'],
    'F': ['A'],
    'D': ['F'],
    'H': ['A']
}


# Perform Depth-Limited Search from 'A' to 'F' with a depth limit of 2
result = depth_limited_search(graph, 'A', 'F',5)
print(result)
