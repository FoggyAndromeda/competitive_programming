n = int(input())
k = int(input())

dp = [[0 for i in range(2)] for j in range(n)]

dp[0][0] = 0
dp[0][1] = k - 1

for i in range(1, n):
    dp[i][0] = dp[i - 1][1]
    dp[i][1] = (k - 1) * (dp[i - 1][0] + dp[i - 1][1])

ans = sum(dp[n - 1])
print(ans)