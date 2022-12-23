n = int(input())
k = int(input())
m = int(input())

matrix = [[k - 1, k - 1], [1, 0]]

result = [[1, 0], [0, 1]]
while (n > 0):
    if (n & 1):
        new_res = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    new_res[i][j] += result[i][k] * matrix[k][j]
                new_res[i][j] %= m
        result = new_res
    new_matrix = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                new_matrix[i][j] += matrix[i][k] * matrix[k][j]
            new_matrix[i][j] %= m
    matrix = new_matrix.copy()
    #print(result, matrix)
    n >>= 1

#print(result)
print(result[0][0] % m)