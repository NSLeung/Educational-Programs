# Using a Python dictionary to act as an adjacency list
graph = {
    'A' : ['B','C'],
    'B' : ['D', 'E'],
    'C' : ['F'],
    'D' : [],
    'E' : ['F'],
    'F' : []
}

# implementation a
# visited = set() # Set to keep track of visited nodes.
# visited = []
# def dfs(visited, graph, node):
#     if node not in visited:
#         print (node)
#         visited.append(node)
#         for neighbor in graph[node]:
#             dfs(visited, graph, neighbor)

visited = []
stack = []
# implementation b
def dfs(visited, graph, start):
    # visited, stack = set(), [start]
    
    stack.append(start)

    while stack:
        s = stack.pop()
        if s not in visited:
            print(s, end=" ")
            visited.append(s)
            # need reversed because we're using stack ?
            for neighbor in reversed(graph[s]):
                stack.append(neighbor)
 

# Driver Code a
# dfs(visited, graph, 'A')

# Driver code b
dfs(visited, graph, 'A')