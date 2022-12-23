def Q(l: int, r: int) -> int:
    if l >= r:
        return 0

    c = 0
    x = A[l]
    i = l - 1
    j = r + 1
    while True:
        while True:
            j -= 1
            c += 1
            if A[j] <= x:
                break

        while True:
            i += 1
            c += 1
            if A[i] >= x:
                break

        if i < j:
            A[i], A[j] = A[j], A[i]
        else:
            m = j
            break

    return c + Q(l, m) + Q(m + 1, r)


N = 3
A = [int(x) for x in input().split()][0:N]

if Q(0, N - 1) == (N * N + 3 * N - 4) / 2:
    print('Vasilisa the Beautiful')
else:
    print('Koschei the Immortal')