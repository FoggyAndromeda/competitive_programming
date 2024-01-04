import sys

def main():
    ans = 0
    for line in sys.stdin.readlines():
        a = [[int(i) for i in line.strip().split()]]
        running = True
        while running:
            a.append([])
            for i in range(len(a[-2]) - 1):
                a[-1].append(a[-2][i + 1] - a[-2][i])
            print(a[-1])
            if any(a[-1]):
                continue
            break
        
        result = 0
        for s in reversed(a):
            result = s[0] - result
        print(result)
        ans += result
    print(ans)

main()
