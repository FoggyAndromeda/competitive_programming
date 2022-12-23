n = int(input())

print(sum(map(int, input().split())) / n)

# sum((p[i] - x)^2) / n = sum(p[i]^2 - 2xp[i] + x^2) = sum(p[i]^2) / n - 2x sum(p[i]) / n + x^2
# der. = -2 sum(p[i]) / n + 2x der. = 0 -> x = sum(p[i]) / n
