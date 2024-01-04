import sys

def main():
    inp = sys.stdin.readlines()
    time = int(''.join(inp[0].strip().split()[1:]))
    dist = int(''.join(inp[1].strip().split()[1:]))

    ans = 0
    for t in range(time):
        if t * (time - t) > dist:
            ans += 1

    print(ans)

main()
