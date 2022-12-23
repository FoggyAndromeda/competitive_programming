n, s = map(int, input().split())

if (s & 1):
    print(0)
    exit()

s //= 2
max_sum = 9 * n

if (s > max_sum):
    print(0)
    exit()

dp = [[0 for i in range(0, max_sum + 1)] for j in range(n)]

for i in range(10):
    dp[0][i] = 1

for i in range(1, n):
    for j in range((i + 1) * 9 + 1):
        for k in range(min(j, 9) + 1):
            dp[i][j] += dp[i - 1][j - k]

print(dp[n - 1][s] * dp[n - 1][s])