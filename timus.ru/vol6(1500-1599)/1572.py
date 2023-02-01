max_size = [
    lambda x : x, # unused
    lambda x : 2 * x, # circle
    lambda x : x * 1.41421356237, # square
    lambda x : x # triangle
]

min_size = [
    lambda x : x,
    lambda x : 2 * x,
    lambda x : x,
    lambda x : x * 0.86602540378
]

ba, bb = map(int, input().split())

k = int(input())

ans = list(filter(lambda x : min_size[x[0]](x[1]) <= max_size[ba](bb), [list(map(int, input().split())) for _ in range(k)]))

print(len(ans))