def onesGroups(grid, queries):
    n = len(grid)
    visited = [[False]*n for _ in range(n)]
    groups = []

    def dfs(r, c, group):
        visited[r][c] = True
        group.append((r,c))
        for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
            nr, nc = r+dr, c+dc
            if nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc]==1 and not visited[nr][nc]:
                dfs(nr, nc, group)

    # find all groups of connected 1's
    for r in range(n):
        for c in range(n):
            if grid[r][c] == 1 and not visited[r][c]:
                group = []
                dfs(r, c, group)
                groups.append(group)

    # count number of groups with sizes that match each query
    res = []
    for q in queries:
        count = sum(1 for group in groups if len(group) == q)
        res.append(count)

    return res
