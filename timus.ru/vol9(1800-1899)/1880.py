n1 = int(input())
a = set(map(int, input().split()))

n2 = int(input())
b = set(map(int, input().split()))

n3 = int(input())
c = set(map(int, input().split()))
print(len(a & b & c))