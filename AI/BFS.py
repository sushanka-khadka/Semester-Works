from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")

        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Example graph represented as an adjacency list
# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [],
#     'E': ['F'],
#     'F': []
# }

# graph ={
#     '0': ['1','3'],
#     '1': ['2','3','5','6'],
#     '2': ['3','4','5'],
#     '3': ['4'],
#     '4':['6'],
#     '5': [],
#     '6':[]
# }


graph ={
    '0': ['1','3'],
    '1': ['0','2','3','5','6'],
    '2': ['1','3','4','5'],
    '3': ['0','1','2','4'],
    '4':['2','3','6'],
    '5': ['1','2'],
    '6':['1','4']
}




# Perform BFS starting from vertex 'A'
bfs(graph, '2')
