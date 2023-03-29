import heapq
def add_extra_edges(g_nodes, g_from, g_to, g_weight):
    # create a set of edges
    edges = set(zip(g_from, g_to))
    # add extra edges with weight 1 between any two distinct nodes that are not already connected by an edge
    for i in range(1, g_nodes+1):
        for j in range(1, g_nodes+1):
            if i != j and (i,j) not in edges:
                g_from.append(i)
                g_to.append(j)
                g_weight.append(1)

def dijkstra(g_nodes, g_from, g_to, g_weight):
    # create a graph represented as a dictionary of dictionaries
    graph = {}
    for i in range(g_nodes):
        graph[i+1] = {}
    for i in range(len(g_from)):
        graph[g_from[i]][g_to[i]] = g_weight[i]
    # initialize the distance dictionary and the heap
    dist = {1: 0}
    heap = [(0, 1)]
    # apply Dijkstra's algorithm
    while heap:
        (d, node) = heapq.heappop(heap)
        if d > dist[node]:
            continue
        for neighbor, weight in graph[node].items():
            if neighbor not in dist or dist[node] + weight < dist[neighbor]:
                dist[neighbor] = dist[node] + weight
                heapq.heappush(heap, (dist[neighbor], neighbor))
    # return the minimum distance to the last node
    return dist[g_nodes]

def minCost(g_nodes, g_from, g_to, g_weight):
    # Write your code here
    add_extra_edges(g_nodes, g_from, g_to, g_weight)
    return dijkstra(g_nodes, g_from, g_to, g_weight)
