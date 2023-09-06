n = int(input())

d = [list(map(int, input().split())) for _ in range(n)]

res = [[d[j][i] for i in range(n)] for j in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            res[i][j] = min(res[i][j], res[i][k] + res[k][j])

for line in res:
    print(*line)
