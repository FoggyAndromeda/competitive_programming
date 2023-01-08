# TODO: upgrade perfomance (0.968s, TL: 1s), rewrite with HFI in cpp

maxn = 3001

dp = [1] * maxn

for i in range(2, maxn):
    dp[i] = i
    for j in range(1, i // 2 + 1):
        dp[i] = max(dp[i], dp[i - j] * dp[j])

print(dp[int(input())])