import sys


sys.setrecursionlimit(2000)


edges = {}

# 1. find fordiben edges using https://programforyou.ru/graph-redactor and Force Algorithm

forbiden = {
    ("ttj", "rpd"),
    ("vps", "htp"),
    ("fqn", "dgc")
}

for line in sys.stdin.readlines():
    vs = line.strip().split()
    a = vs[0][:-1]

    if not a in edges:
        edges[a] = []

    for b in vs[1:]:
        if (a, b) in forbiden or (b, a) in forbiden:
            continue

        if not b in edges:
            edges[b] = []
        
        edges[a].append(b)
        edges[b].append(a)
 
visited = set()


def dfs(v):
    visited.add(v)
    res = 1
    for nxt in edges[v]:
        if nxt in visited:
            continue
        res += dfs(nxt)
    return res


for v in edges.keys():
    if not v in visited:
        print(dfs(v))
