def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=" ")

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Example graph represented as an adjacency list
# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [],
#     'E': ['F'],
#     'F': []
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



# Perform DFS starting from vertex 'A'
dfs(graph, '6')
