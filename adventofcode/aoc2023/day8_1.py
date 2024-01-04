import sys

def main():
    path = sys.stdin.readline().strip()
    sys.stdin.readline()
    nexts = [s.strip() for s in sys.stdin.readlines()]
    children = {}
    for nxt in nexts:
        children[nxt[:3]] = (nxt[7:10], nxt[12:15])

    place = "AAA"
    now_move = 0
    while place != "ZZZ":
        place = children[place][path[now_move % len(path)] == 'R']
        now_move += 1
    print(now_move)

main()