# graph represented as adjacency list
graph = {
  'A' : ['B','C'],
  'B' : ['D', 'E'],
  'C' : ['F'],
  'D' : [],
  'E' : ['F'],
  'F' : []
}

visited = [] # List to keep track of visited nodes.
queue = []     #Initialize a queue

def bfs(visited, graph, node):
    # 1. pick any node, visit it first
    visited.append(node)
    # 2. add to queue
    queue.append(node)

    while queue:
        s = queue.pop(0) 
        print (s, end = " ") 

        # explore neighbors of s first
        for neighbor in graph[s]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)

# Driver Code
bfs(visited, graph, 'A')