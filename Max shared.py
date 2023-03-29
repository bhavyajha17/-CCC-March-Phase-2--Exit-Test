def maxShared(friends_nodes, friends_from, friends_to, friends_weight):
    # Write your code here
    res = {}                                                 # Edge frequency’s dictionary
    for i in range(len(friends_from)):          # for range of length of friends_from
       a = min(friends_from[i], friends_to[i])
       b = max(friends_from[i], friends_to[i])
       # Edge is given if in case it is not present already
       if res.get((a, b)) is None:
           res[(a, b)] = 1
       else:
           # Otherwise frequency is incremented
           res[(a, b)] += 1
    Ans = 0
    max_Connection = 0
    # Maximum no. of connection is searched
    for Edge in res.keys():
       max_Connection = max(max_Connection, res[Edge])
    # Maximum product of edge and maximum connection is found
    for Edge in res.keys():
       if res[Edge] == max_Connection:
           Ans = max(Ans, Edge[0] * Edge[1])
   # Output is returned
    return Ans
