parent = []
def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]
def union(x, y):
    px = find(x) 
    py = find(y)
    if(px == py):
        return False
    parent[px] = py
    return True
     
def tasks(n, a, b):
    global parent
    parent = [x for x in range(n+1)]
    c=0
    for x,y in zip(a,b):
        if(not union(x,y)):
            c+=1

    return n  - c
