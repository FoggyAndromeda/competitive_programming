import sys

INF = 1e9

possible_dir = {
    '|' : {"U", "D"},
    '-' : {"L", "R"},
    'J' : {"U", "L"},
    'L' : {"U", "R"},
    '7' : {"D", "L"},
    'F' : {"D", "R"},
    'S' : {"L", "R", "U", "D"},
    '.' : {}
}

def main():
    mp = sys.stdin.readlines()
    mp = [s.strip() for s in mp]
    n = len(mp)
    m = len(mp[0])

    sx, sy = -1, -1
    
    for i in range(n):
        for j in range(m):
            if mp[i][j] == 'S':
                sx, sy = i, j

    st = [(sx, sy, 0)]
    dist = [[INF] * m for _ in range(n)]
    while len(st) > 0:
        x, y, d = st.pop()
        if dist[x][y] < d:
            continue 
        dist[x][y] = min(dist[x][y], d)
        if x > 0 and 'U' in possible_dir[mp[x][y]] and 'D' in possible_dir[mp[x - 1][y]]:
            st.append((x - 1, y, d + 1))
        if x < n - 1 and 'D' in possible_dir[mp[x][y]] and 'U' in possible_dir[mp[x + 1][y]]:
            st.append((x + 1, y, d + 1))
        if y > 0 and 'L' in possible_dir[mp[x][y]] and 'R' in possible_dir[mp[x][y - 1]]:
            st.append((x, y - 1, d + 1))
        if y < m - 1 and 'R' in possible_dir[mp[x][y]] and 'L' in possible_dir[mp[x][y + 1]]:
            st.append((x, y + 1, d + 1))
    ans = 0
    for i in range(n):
        for j in range(m):
            if dist[i][j] != INF:
                ans = max(dist[i][j], ans)
            else:
                dist[i][j] = 0
    for line in dist:
        for i in line:
            print(i, end = ' ')
        print()
    print(ans)
                

main()
