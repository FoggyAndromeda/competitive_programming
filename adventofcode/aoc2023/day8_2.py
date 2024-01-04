import sys
from math import lcm

def main():
    path = sys.stdin.readline().strip()
    sys.stdin.readline()
    nexts = [s.strip() for s in sys.stdin.readlines()]
    children = {}
    for nxt in nexts:
        children[nxt[:3]] = (nxt[7:10], nxt[12:15])

    places = list(filter(lambda s : s[-1] == 'A', children.keys()))
    is_end = [False] * len(places)
    print(places)

    ans = 1
    for place in places:
        now_move = 0
        while place[-1] != "Z":
            place = children[place][path[now_move % len(path)] == 'R']
            now_move += 1
        print(now_move, ans)
        ans = lcm(ans, now_move)
    print(ans)

main()
