n, k, d = map(int, input().split())

dp = [[0] * 2 for _ in range(n + 1)]

mod = 10**9 + 7

dp[0][0] = 1
for i in range(1, n + 1):
    for j in range(1, d):
        if j > i: break
        dp[i][0] += dp[i - j][0]
        dp[i][0] %= mod
        dp[i][1] += dp[i - j][1]
        dp[i][1] %= mod
    for j in range(d, k + 1):
        if j > i: break
        dp[i][1] += dp[i - j][0] + dp[i - j][1]
        dp[i][1] %= mod
    
print(dp[-1][1])