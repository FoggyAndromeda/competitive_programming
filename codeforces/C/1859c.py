def solve():
    n = int(input())
    ans = 0
    for pref in range(n):
        ind = 1
        now_cnt = 0
        now_m = 0
        for i in range(1, pref + 1):
            now_cnt += i * ind
            now_m = max(now_m, i * ind)
            ind += 1
        for i in range(n, pref, -1):
            now_cnt += i * ind
            now_m = max(now_m, i * ind)
            ind += 1
 
        ans = max(ans, now_cnt - now_m)
    print(ans)


def main():
    t = int(input())
    for _ in range(t):
        solve()

main()
