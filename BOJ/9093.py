T = int(input())
for _ in range(T):
    A = input().split()
    for a in A: print(a[::-1], end=' ')
    print()